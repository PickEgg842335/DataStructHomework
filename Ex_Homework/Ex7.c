#include <stdio.h>
#define V 8
#define MAX 10000

typedef struct PathNode {
	int start;
	int end;
	int distance;
    struct Node *next;
} strPathNode;
strPathNode *PathHead[7] = {NULL};

struct Edge {
	int start;
	int end;
	int distance;
} edges[] = {{0, 1, 160}, {0, 6, 50}, {0, 7, 30}, {1, 2, 180},
			 {2, 3, 60}, {2, 4, 800}, {2, 5, 53}, {3, 4, 50},
			 {5, 2, 66}, {5, 4, 180}, {6, 5, 100},
		     {7, 1, 120}, {7, 5, 140}, {7, 6, 80}};
int cost[V][V];
int mark[V] = {0}; //記錄已找到最短路徑的nodes 
int dist[V]; // 記錄起始node到每一個node的最短路徑 

void addEdge(int n) {
	for (int i = 0; i < n; i++)
		cost[edges[i].start][edges[i].end] = edges[i].distance;
}

strPathNode *addPathData(strPathNode *head, int startValue, int endValue, int distanceValue)
{
	strPathNode *newb = (strPathNode*)malloc(sizeof(strPathNode)); 
    newb->start = startValue;
    newb->end = endValue;
    newb->distance = distanceValue;
	newb->next = NULL;

	if (head == NULL) 
    {
		head = newb;
	} 
    else 
    {
		strPathNode *p = head;
		while (p->next != NULL)
		{
			p = p->next;
        }
		p->next = newb;
	}
	
	return(head);
}

void deleteAllPath(strPathNode *head) 
{
    strPathNode *ptr = head;
    strPathNode *preNode = NULL;
    
    if (head == NULL) 
    {
        return;
    }

    while(ptr != NULL)
    {
        preNode = ptr;
        free(preNode);
        ptr = ptr->next;
    }
}

strPathNode *CopyHeadPath(strPathNode *Sourcehead) 
{
    strPathNode *Sourceptr = Sourcehead;
    strPathNode *newHead = NULL;
    strPathNode *newPtr = NULL;

    if (Sourcehead == NULL) 
    {
        return(NULL);
    }
    while(Sourceptr != NULL)
    {
    	strPathNode *newb = (strPathNode*)malloc(sizeof(strPathNode)); 
        newb->start = Sourceptr->start;
        newb->end = Sourceptr->end;
        newb->distance = Sourceptr->distance;
    	newb->next = NULL;
        if(Sourceptr == Sourcehead)
        {
            newHead = newb;
            newPtr = newHead;
        }
        else
        {
            newPtr->next = newb;
            newPtr = newb;
        }
        Sourceptr = Sourceptr->next;
    }

    return(newHead);
}

void outputCost() {
	printf("有向圖的鄰接矩陣表示法:\n\n");
	for (int i = 0; i < V; i++)
        printf("\tv%d", i);
    printf("\n-------------------------------------------------------------------\n");
    for (int i = 0; i < V; i++) {
    	printf("v%d |", i);
    	for (int j = 0; j < V; j++) {
    		if (cost[i][j] == MAX)
    			printf("\t%c", 'x');
    		else
    			printf("\t%d", cost[i][j]);
    	}
    	printf("\n");
	}
}

void shortestPath(int start) 
{
	for (int i = 0; i < V; i++)
	{
	   dist[i] = cost[start][i];
	   PathHead[i] = addPathData(PathHead[i], start, i, dist[i]);
    }
    dist[start] = 0;
    mark[start] = 1;
    deleteAllPath(PathHead[start]);
    PathHead[start] = addPathData(PathHead[start], start, start, 0);
    int path_done = 2; 
    while (path_done < V) 
    {
    	int min = MAX;
    	int node = -1; //找出未被選取之頂點中距離最少者
    	for (int i = 0; i < V; i++) 
        { 
    		if (mark[i] == 0 && dist[i] < min) 
            {
    			min = dist[i];
    			node = i;    			
			}		
		}
		if (node == -1)  // no any paths
		{
			break;
        }
		else 
        {
			mark[node] = 1;
			for (int i = 0; i < V; i++) 
            {
				if (mark[i] == 0 && (dist[node] + cost[node][i]) < dist[i]) 
                {
					dist[i] = dist[node] + cost[node][i];
				    deleteAllPath(PathHead[i]);
				    PathHead[i] = CopyHeadPath(PathHead[node]);
				    PathHead[i] = addPathData(PathHead[i], node, i, cost[node][i]);
				    
				        strPathNode *p = PathHead[i];
                        while(p != NULL)
                        {
                            printf("%d %d %d\n", i, p->start, p->end);
                            p = p->next;
                        }
                        printf("-------------------------\n");
				}
			}
			path_done++;
		}  	
	}
}

void outputDist(int start) {
	printf("\n從頂點%d到其餘每一頂點的最短距離為: \n\n", start);
	for (int i = 0; i < V; i++)
        printf("\t[%d]", i);
    printf("\n-------------------------------------------------------------------\n");
    for (int i = 0; i < V; i++) {
    	if (dist[i] == MAX)
    		printf("\t%c", 'x');
    	else
    		printf("\t%d", dist[i]);
	}
}

void outputPath(int start) 
{
	printf("\n\n從頂點%d到其餘每一頂點的詳細路徑為: \n\n", start);
    printf("\t起點\t終點\t\t最短路徑\t\t\t最短距離");
    printf("\n----------------------------------------------------------------------------\n");
	for (int i = 0; i < V; i++)
	{
	    int wtabCnt = 0;
        if(i != start)
        {
            printf("\t%d\t%d\t\t", start, i);
            strPathNode *p = PathHead[i];
            if(dist[i] == MAX)
            {
                printf("***************\t\t\t***\n");
            }
            else
            {
                while(p != NULL)
                {
                    if(p->next != NULL)
                    {
                        printf("%d→", p->start);
                    }
                    else
                    {
                        printf("%d→%d", p->start, p->end);
                    }
                    p = p->next;
                    ++wtabCnt;
                }
                
                switch(wtabCnt)
                {
                    case 1:
                    case 2:
                        printf("\t\t\t\t");
                        break;
                    case 3:
                    case 4:
                        printf("\t\t\t");
                        break;
                    case 5:
                    case 6:
                        printf("\t\t");
                        break;
                    default:
                        break;
                }
                printf("%d\n", dist[i]);
            }
            printf("----------------------------------------------------------------------------\n");
        }
    } 
    printf("----------------------------------------------------------------------------\n");
}

void main() {
	for (int i = 0; i < V; i++)
    	for (int j = 0; j < V; j++)
    		cost[i][j] = MAX;
	int n = sizeof(edges) / sizeof(edges[0]);
	addEdge(n);
	outputCost();
	int start;
	printf("\n輸入從那個頂點出發: ");
    scanf("%d", &start);
    shortestPath(start);
    outputDist(start);
    outputPath(start);
}
