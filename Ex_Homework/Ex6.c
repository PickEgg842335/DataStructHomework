#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int wDataType;
	char bCharData;
    struct Node *left;
    struct Node *right;
} Node;
Node *root = NULL;

char result[100];
int  stack[100];
int  stack_idx = -1;
int  stack2[100];
int  stack2_idx = -1;

int prec(char); // 設定運算子的優先順序 
void insert(int wDataType, char bData);
void infixToBinarytree(char expr[]);
void preorder(Node*);
void inorder(Node*);
void postorder(Node*);

void main()
{
    char expr[] = "A-B*(C+D)/E";

	printf("原始數列: ");
    for(int i = 0; i < strlen(expr); i++)
    {
        printf("%c ", expr[i]);
    }
    infixToBinarytree(expr);
    printf("\n前序: ");
	preorder(root);
	printf("\n中序: ");
	inorder(root);
	printf("\n後序: ");
	postorder(root);	
    printf("\n\n");

    char expr1[] = "A+B-C*(D+E)/F";

	printf("原始數列: ");
    for(int i = 0; i < strlen(expr1); i++)
    {
        printf("%c ", expr1[i]);
    }
    infixToBinarytree(expr1);
    printf("\n前序: ");
	preorder(root);
	printf("\n中序: ");
	inorder(root);
	printf("\n後序: ");
	postorder(root);	
}

int prec(char c)
{
    if(c == '\0')
    {
        return 4;
    }
    else if (c == '/' || c == '*')
    {
        return 3;
    }
    else if (c == '+' || c == '-')
    {
        return 2;
    }
    else if (c == '(' || c == ')')
    {
        return 1;
    }
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        return 0;
    } 
    else
    {
        return -1;
    }
}

void insert(int wDataType, char bData)
{
	Node *newb = (Node*)malloc(sizeof(Node));
	newb->wDataType = wDataType;
    newb->bCharData = bData;
	newb->left = NULL;
	newb->right = NULL;
	Node *Nodetemp = NULL;
	Node *Nodetemp2 = NULL;
	Node *pretemp = NULL;
	Node *pretemp2 = NULL;

    switch(wDataType)
    {
        case 0:
            stack2[++stack2_idx] = newb;
            break;
        case 1:
            if(newb->bCharData == '(')
            {
                stack[++stack_idx] = newb;
                Node *p= stack[stack_idx];
            }
            else if(newb->bCharData == ')')
            {
                Nodetemp = newb;
                pretemp = newb;
                while(Nodetemp->bCharData != '(')
                {
                    Nodetemp = stack[stack_idx--];
                    Nodetemp2 = stack2[stack2_idx--];
                    if(Nodetemp->bCharData == '(')
                    {
                        if(pretemp == newb)
                        {
                            break;
                        }
                        else
                        {
                            pretemp2 = pretemp;
                            while(pretemp->right != NULL)
                            {
                                pretemp = pretemp->right;
                            }
                            pretemp->right = newb;
                            pretemp = pretemp2;
                            while(pretemp->left != NULL)
                            {
                                pretemp = pretemp->left;
                            }
                            pretemp->left = Nodetemp;
                            stack2[++stack2_idx] = pretemp2;
                        }
                    }
                    else
                    {
                        Nodetemp->right = Nodetemp2;
                        stack2[++stack2_idx] = Nodetemp;
                        pretemp = Nodetemp;
                    }
                }
            }
            break;
        case 2:
        case 3:
            if(stack_idx >= 0)
            {
                Nodetemp = stack[stack_idx];
                if(prec(newb->bCharData) <= prec(Nodetemp->bCharData))
                {
                    Nodetemp2 = stack2[stack2_idx--];
                    Nodetemp->right = Nodetemp2;
                    stack[stack_idx--] = NULL;
                    stack2[++stack2_idx] = Nodetemp;
                }
            }
            Nodetemp2 = stack2[stack2_idx];
            newb->left = Nodetemp2;
            stack2[stack2_idx--] = NULL;
            stack[++stack_idx] = newb;
            break;
        case 4:
            while((stack_idx >= 0) || (stack2_idx >= 0))  
            {
                if(stack_idx < 0)
                {
                    Nodetemp = stack2[stack2_idx--];
                    root = Nodetemp;
                }
                else
                {
                    Nodetemp = stack[stack_idx--];
                    Nodetemp2 = stack2[stack2_idx--];
                    Nodetemp->right = Nodetemp2;
                    stack2[++stack2_idx] = Nodetemp;
                }
            }
            free(newb);
            break;
        default:
            free(newb);
            break;
    }
}

void infixToBinarytree(char expr[])
{
    for(int i = 0; i < (strlen(expr) + 1); i++)
    {
        insert(prec(expr[i]),expr[i]);
    }
}
 
void preorder(Node* root) {
    if (root != NULL) {
        if((root->bCharData != '(' ) && (root->bCharData != ')' ))
        { 
            printf("%c ", root->bCharData);
        } 
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->bCharData);
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        if((root->bCharData != '(' ) && (root->bCharData != ')' ))
        { 
            printf("%c ", root->bCharData);
        } 
    }
}
