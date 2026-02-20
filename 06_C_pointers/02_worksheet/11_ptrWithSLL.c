/*
11. Pointer and Linked List
Goal: Implement a singly linked list using pointers for node management and dynamic memory allocation.

Activity:

Define a node structure with data and next pointer.
Log Session functions to add nodes at the beginning, end, or middle of the list using pointers.
Traverse the list using pointers to access and print data.
Delete nodes and free memory dynamically.
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;

/* Add node at last */
node *addLast(node *head){
    node *new=NULL,*temp;
    new=(node*)calloc(1,sizeof(node));
    if(new==NULL){
        printf("ERROR:Memory allocation Failed\n");
        return head;
    }
    printf("Enter data:");
    scanf("%d",&new->data);
    if(head==NULL) head=new;
    else{
        temp=head;
        while(temp->next)
            temp=temp->next;
        temp->next=new;
    }
    return head;
}

/* add node at first */
node * addFirst(node *head){
    node *new=NULL;
    new=(node*)calloc(1,sizeof(node));
    if(new==NULL){
        printf("ERROR:Memory allocation Failed\n");
        return head;
    }
    printf("Enter data:");
    scanf("%d",&new->data);
    if(head==NULL) head=new;
    else{
        new->next=head;
        head=new;
    }
    return head;
}

/* print nodes */
void print(node *head){
    while (head)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("null\n\n");
}

/* delete first*/
node *deleteFirst(node *head){
    node *temp=head;
    if(head==NULL) printf("Empty List\n\n");
    else{
        head=head->next;
        free(temp);
    }
    return head;
}

/* Delete last */
node *deleteLast(node *head)
{
    node *temp=head;
    if(head==NULL)
        printf("Empty list\n\n");
    else if(head->next ==NULL){
        free(head);
        return NULL;
    }
    else{
        while(temp->next->next)
            temp=temp->next;
        free(temp->next);
        temp->next=NULL;
    }
    return head;
}
int main(){
    node *head=NULL;
    head=addLast(head);
    head=addFirst(head);
    head=addLast(head);
    head=addLast(head);
    print(head);
    head=deleteFirst(head);
    head=deleteLast(head);
    print(head);
}