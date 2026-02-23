/*
18. Alternate Node Merging Challenges
Question:
Write a C program to merge alternate nodes of two linked lists.

Sample data:
List1: 9 7 5
List2: 10 8 6

Expected output:
Merged list: 9 10 7 8 5 6

19. Alternate Interleaving Challenges
Question:
Write a C program to interleave two lists alternatively.

Sample data:
List1: 1 3 5
List2: 2 4 6

Expected output:
Result: 1 2 3 4 5 6
*/
#include<stdio.h>
#include<stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    node *next;
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

/* Alternate Node Merging Challenges */
node* mergeAlternate(node* l1,node* l2){
    if (!l1) return l2;
    if (!l2) return l1;
    node *head=l1,*l1_next,*l2_next;
    while(l1 && l2){
        l1_next=l1->next;
        l2_next=l2->next;
        l1->next=l2;
        if(!l1_next)
            break;
        l2->next=l1_next;
        l1=l1_next;
        l2=l2_next;
    }
    return head;
}

/* Alternate Interleaving Challenges*/
node* interleave(node* l1,node* l2) {
    node dummy;
    node *tail=&dummy;
    dummy.next=NULL;
    while(l1 && l2){
        tail->next=l1;
        l1=l1->next;
        tail=tail->next;
        tail->next=l2;
        l2=l2->next;
        tail=tail->next;
    }
    if(l1)
        tail->next=l1;
    else
        tail->next=l2;
    return dummy.next;
}
int main(){
    node *l1=NULL,*l2=NULL,*head=NULL;
    for(int i=0;i<5;i++)
        l1=insert(l1);
    for(int i=0;i<5;i++)
        l2=insert(l2);
    head=mergeAlternate(l1,l2);
    print(head);
    return 0;
}