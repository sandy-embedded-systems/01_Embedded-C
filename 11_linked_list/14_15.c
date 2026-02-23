/*
14. Pairwise Reversal Challenges
Question:
Write a C program to reverse nodes in pairs.

Sample data:
List: 1 2 3 4 5

Expected output:
Reversed in pairs: 2 1 4 3 5

15. Block Reversal Variants
Question:
Write a C program to reverse nodes in blocks of size k.

Sample data:
List: 1 2 3 4 5 6
k = 3

Expected output:
Reversed: 3 2 1 6 5 4
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
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

/* Pairwise Reversal Challenges */
node* reversePairs(node* head){
    if(!head|| !head->next)
        return head;
    node *prev=NULL;
    node *curr=head;
    node *newHead=head->next;
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
    return newHead;
}

/* Block Reversal Variants */
node* reverseK(node* head, int k){
    if(!head)
        return NULL;
    node *prev=NULL;
    node *curr=head;
    node *next=NULL;
    int count=0;
    while(curr &&count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next)
        head->next=reverseK(next,k);
    return prev;
}
int main(){
    node *head=NULL;
    for(int i=0;i<5;i++)
        head=insert(head);
    print(head);
    reversePairs(head);
    printf("list after pairwise swap:");
    print(head);
    printf("List after block reversal: ");
    reverseK(head,3);
    print(head);
    return 0;
}