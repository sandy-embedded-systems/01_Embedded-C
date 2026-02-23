/*
20. Adjacent Node Swapping Variants
Question:
Write a C program to swap every two adjacent nodes.

Sample data:
List: 1 2 3 4 5
 
Expected output:
Swapped list: 2 1 4 3 5
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
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

node* swapAdjacent(node* head){
    if (!head|| !head->next)
        return head;
    node *prev=NULL;
    node *curr=head;
    head=head->next;
    while(curr &&curr->next){
        node *nextPair=curr->next->next;
        node *second=curr->next;
         second->next=curr;
        curr->next=nextPair;
        if(prev)
            prev->next=second;
        prev=curr;
        curr=nextPair;
    }
    return head;
}
int main(){
    node *head=NULL;
    for(int i=0;i<5;i++)
        head=insert(head);
    swapAdjacent(head);
    print(head);
    return 0;
}