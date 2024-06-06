#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; 
    struct Node *next;
} Node;
Node *head = NULL;

void append(int value);
void insert(Node *ptr, int value);
void delete(Node *ptr);
Node *find(int value);
void traverse(void);
int length(void);
void reverse(void);

void main() {
    append(54);
    append(12);
    append(30);
    append(25);
    Node *ptr = find(30);
    insert(ptr, 67);
    traverse();
    printf("Have %d Nodes\n", length());
    reverse();
    traverse();
    printf("Have %d Nodes\n", length());
    reverse();
    ptr = find(30);
    delete(ptr);
    traverse();
    printf("Have %d Nodes\n", length());
    reverse();
    traverse();
    printf("Have %d Nodes\n", length());
}

/* append tail Node with value */ 
void append(int value) {
    Node *newb = (Node*)malloc(sizeof(Node)); 
    newb->data= value;
    newb->next = NULL;
        
    if (head == NULL) {
        head = newb;
    } else {
        Node *p = head;
        while (p->next != NULL) 
            p = p->next;
        p->next = newb;
    }
}

/* insert a Node with value before ptr Node */ 
void insert(Node *ptr, int value) {
    Node *newb = (Node*)malloc(sizeof(Node)); 
    newb->data= value;
    newb->next = NULL;
    
    if (ptr == NULL) { 
        append(value);
    } else {
        newb->next = ptr;
        if (ptr == head)
            head = newb;
        else {
            Node *p = head;
            while (p->next != ptr)
                p = p->next;
            p->next = newb;
        }
    }
}

void delete(Node *ptr) { 
    if (ptr == NULL) return;
    if (ptr == head) { // �Ĥ@�ر��p: �R���Ĥ@�Ӹ`�I 
        head = head->next; 
    } else { 
        Node *p = head; 
        while (p->next != ptr) // ��`�Iptr���e�`�I
            p = p->next; 
        p->next = ptr->next;
    }
    free(ptr);
}

Node *find(int value) { 
    Node *p = head;
    while (p != NULL) {
        if (p->data == value) 
            return p; 
           p = p->next;
    }		
    return p; 
}

void traverse() {
    printf("[");
    Node *p = head;
    while (p != NULL) {
        if (p == head)
            printf("%d", p->data);
        else
            printf(",%d", p->data);
        p = p->next;
    }
    printf("]\n");
}

int length() { 
    int count = 0; 
    Node *p = head; 
    while (p != NULL) { 
        count++;
        p = p->next;
    } 
    return count; 
}

void reverse(void)
{
    Node *p = head;
    Node *pPrev = NULL;

    while (p != NULL) 
    {
        if (p->next == NULL)
        {
            p = p->next;
            head->next = pPrev;
        }
        else
        {
            p = p->next;
            head->next = pPrev;
            pPrev = head;
            head = p;
        }
    }
} 
