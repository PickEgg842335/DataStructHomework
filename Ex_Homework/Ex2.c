#include <stdio.h>
#include <stdlib.h>

const int equation1[5][2] = {{3,5},{8,4},{12,3},{3,1},{19,0}}; // 3(x^5)+8(x^4)+12(x^3)+3(x)+19
const int equation2[6][2] = {{1,6},{16,5},{1,3},{7,2},{23,1},{39,0}}; //(x^6)+16(x^5)+(x^3)+7(x^2)+23(x)+39

typedef struct Node {
    int data[2];
    struct Node *next;
} Node;
Node *head1 = NULL;
Node *head2 = NULL;
Node *Outputhead = NULL;

Node *appendEquation(Node *headptr, int row, int column,int *value);
Node *TwoEquMultCal(Node *headptr1, Node *headptr2, Node *Outputheadptr);
void EquationPrinter(Node *headptr);

Node *append(Node *headptr, int *value, int wLength);
Node *insert(Node *headptr, Node *ptr, int *value, int wLength);
Node *delete(Node *headptr, Node *ptr);
Node *find(Node *headptr, int *value, int findtype);
void traverse(Node *headptr);
int length(Node *headptr);
Node *reverse(Node *headptr);

void main() 
{
    head1 = appendEquation(head1, 5, 2, equation1);
    head2 = appendEquation(head2, 6, 2, equation2);
    printf("輸入方程式1:\n");
    EquationPrinter(head1);
    printf("輸入方程式2:\n");
    EquationPrinter(head2);
    Outputhead = TwoEquMultCal(head1, head2, Outputhead);
    printf("相乘後得解方程式:\n");
    EquationPrinter(Outputhead);
}

Node *appendEquation(Node *headptr, int row, int column,int *value)
{
    for(int i = 0; i < row; i++)
    {
        headptr = append(headptr, value + (i * column), column);
    }
    return(headptr);
}

Node *TwoEquMultCal(Node *headptr1, Node *headptr2, Node *Outputheadptr)
{
    Node *p1 = headptr1;
    Node *p2 = headptr2;
    int head1Length = length(headptr1);
    int head2Length = length(headptr2);
    int CalResult[2];

    p1 = headptr1;
    for(int i = 0; i < head1Length; i++)
    {
        p2 = headptr2;
        for(int j = 0; j < head2Length; j++)
        {
            CalResult[0] = p1->data[0] * p2->data[0];
            CalResult[1] = p1->data[1] + p2->data[1];
            Node *ptr = find(Outputheadptr,CalResult,2);
            if(ptr != NULL)
            {
                ptr->data[0] += CalResult[0];
            }
            else
            {
                for(int k = CalResult[1]; k >= 0; k--)
                {
                    int DataChk[2] = {0, k};
                    Node *ptr = find(Outputheadptr, DataChk, 2);
                    if(((ptr == NULL) && (k == 0)) || (ptr != NULL))
                    {
                        Outputheadptr = insert(Outputheadptr, ptr, CalResult, 2);
                        break;
                    }
                }
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return(Outputheadptr);
}


void EquationPrinter(Node *headptr)
{
    Node *p = headptr;
    while (p != NULL) 
    {
        if (p == headptr)
        {
            if(p->data[1] != 0)
            {
                if(p->data[0] > 0)
                {
                    printf("%d(x^%d)", p->data[0], p->data[1]);
                }
                else if(p->data[0] < 0)
                {
                    printf("-%d(x^%d)", p->data[0], p->data[1]);
                }
            }
            else
            {
                if(p->data[0] > 0)
                {
                    printf("%d", p->data[0]);
                }
                else if(p->data[0] < 0)
                {
                    printf("-%d", p->data[0]);
                }
            }
        }
        else
        {
            if(p->data[1] != 0)
            {
                if(p->data[0] > 0)
                {
                    printf("+%d(x^%d)", p->data[0], p->data[1]);
                }
                else if(p->data[0] < 0)
                {
                    printf("-%d(x^%d)", p->data[0], p->data[1]);
                }
            }
            else
            {
                if(p->data[0] > 0)
                {
                    printf("+%d", p->data[0]);
                }
                else if(p->data[0] < 0)
                {
                    printf("-%d", p->data[0]);
                }
            }
        }
        p = p->next;
    }
    printf("\n");
}

/* append tail Node with value */ 
Node *append(Node *headptr, int *value, int wLength)
{
    Node *newb = (Node*)malloc(sizeof(Node)); 
    newb->next = NULL;

    for(int i = 0; i < wLength; i++)
    {
        newb->data[i] = *(value + i);
    }
    if (headptr == NULL) 
    {
        headptr = newb;
    }
    else 
    {
        Node *p = headptr;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newb;
    }
    return(headptr);
}

/* insert a Node with value before ptr Node */ 
Node *insert(Node *headptr, Node *ptr, int *value, int wLength)
{
    Node *newb = (Node*)malloc(sizeof(Node)); 
    newb->next = NULL;
    
    for(int i = 0; i < wLength; i++)
    {
        newb->data[i] = *(value + i);
    }
    
    if (ptr == NULL) 
    { 
        headptr = append(headptr, value, wLength);
    }
    else
    {
        newb->next = ptr;
        if (ptr == headptr)
        {
            headptr = newb;
        }
        else 
        {
            Node *p = headptr;
            while (p->next != ptr)
            {
                p = p->next;
            }
            p->next = newb;
        }
    }
    return(headptr);
}

Node *delete(Node *headptr, Node *ptr)
{ 
    if (ptr == NULL)
    {
        return(headptr);
    }
    if (ptr == headptr) 
    {
        headptr = headptr->next; 
    }
    else
    { 
        Node *p = headptr; 
        while (p->next != ptr)
        {
            p = p->next; 
        }
        p->next = ptr->next;
    }
    free(ptr);
    return(headptr);
}

Node *find(Node *headptr, int *value, int findtype) 
{
    Node *p = headptr;
    int value1 = *value;
    int value2 = *(value + 1);
    
    while (p != NULL)
    {
        if(((p->data[0] == value1) && (findtype == 1))
            || ((p->data[1] == value2) && (findtype == 2)))
        {
            return p; 
        }
        p = p->next;
    }		
    return p; 
}

void traverse(Node *headptr) 
{
    printf("[");
    Node *p = headptr;
    while (p != NULL) 
    {
        if (p == headptr)
        {
            printf("{%d, %d}", p->data[0], p->data[1]);
        }
        else
        {
            printf(",{%d, %d}" , p->data[0], p->data[1]);
        }
        p = p->next;
    }
    printf("]\n");
}

int length(Node *headptr)
{ 
    int count = 0; 
    Node *p = headptr; 
    while (p != NULL) 
    { 
        count++;
        p = p->next;
    } 
    return count; 
}

Node *reverse(Node *headptr)
{
    Node *p = headptr;
    Node *pPrev = NULL;

    while (p != NULL) 
    {
        if (p->next == NULL)
        {
            p = p->next;
            headptr->next = pPrev;
        }
        else
        {
            p = p->next;
            headptr->next = pPrev;
            pPrev = headptr;
            headptr = p;
        }
    }
    return(headptr);
} 
