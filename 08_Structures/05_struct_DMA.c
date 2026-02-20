/*
5. Dynamic Memory with Structures
Goal
Understand how to allocate and free memory dynamically for structures, including use cases like linked lists and memory pools in embedded systems.

Activity
Use malloc() to allocate a structure dynamically and assign values to members.
Build a simple singly linked list using structure and pointers.
Implement a queue using structure-based nodes.
Write a memory pool manager that uses an array of structures and a free list.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct student *next;
}node;
node *insert(node* head){
    node *new=calloc(1,sizeof(node));
    printf("enter data:");
    scanf("%d",&new->data);
    if(head==NULL) head=new;
    else{
        node *temp=head;
        while(temp->next)
            temp=temp->next;
        temp->next=new;
    }
    return head;
}
void print(node *head){
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("null\n");
}
void free_list(node *head){
    while (head)
    {
        free(head);
        head=head->next;
    }
}
void simple_list(void){
    node *head=NULL;
    for(int i=0;i<5;i++)
        head=insert(head);
    print(head);
    free_list(head);
}

int main(){
    simple_list();
    return 0;
}