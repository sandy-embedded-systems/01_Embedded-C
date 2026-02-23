/*
16. Alternate K-Node Reversal Challenges
Question:
Write a C program to reverse alternate k nodes.

Sample data:
List: 1 2 3 4 5 6 7 8
k = 2

Expected output:
Reversed: 2 1 3 4 6 5 7 8

17. Halving the List Challenges
Question:
Write a C program to split a list into two halves.

Sample data:
List: 1 2 3 4 5 6

Expected output:
First half: 1 2 3
Second half: 4 5 6
*/
#include<stdio.h>
#include<stdlib.h>
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

/* Alternate K-Node Reversal Challenges */
node* reverseAlternateK(node* head,int k){
    if(!head)
        return NULL;
    node *curr=head;
    node *prev=NULL;
    node *next=NULL;
    int count=0;
    while(curr && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(head)
        head->next=curr;
    count=0;
    while(count<k-1 && curr){
        curr=curr->next;
        count++;
    }
    if(curr)
        curr->next=reverseAlternateK(curr->next,k);
    return prev;
}
void splitList(node* head,
               node** firstHalf,
               node** secondHalf){
    if (!head|| !head->next) {
        *firstHalf=head;
        *secondHalf=NULL;
        return;
    }
    node *slow=head;
    node *fast=head->next;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    *firstHalf=head;
    *secondHalf=slow->next;
    slow->next=NULL;  
}
int main(){
    node *head=NULL,*first=NULL,*second=NULL;
    for(int i=0;i<6;i++){
        head=insert(head);
    }
    print(head);
    head=reverseAlternateK(head,2);
    print(head);
    printf("lists after split:\n");
    splitList(head,&first,&second);
    print(first);
    print(second);
    return 0;
}