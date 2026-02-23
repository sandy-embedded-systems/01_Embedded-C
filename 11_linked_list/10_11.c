/*
10. Linked List Sorting Challenges
Question:
Write a C program to sort a singly linked list using merge sort.

Sample data:
List: 2 3 1 7 5

Expected output:
Sorted list: 1 2 3 5 7

11. Nth Node from End Variants
Question:
Write a C program to retrieve the nth node from the end.

Sample data:
List: 1 3 5 11
n = 3

Expected output:
Result: 3
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

/* sort a singly linked list using merge sort. */
node* merge(node* a,node* b){
    if (!a) return b;
    if (!b) return a;
    node* result=NULL;
    if(a->data<=b->data){
        result=a;
        result->next=merge(a->next,b);
    }
    else{
        result->next=merge(a,b->next);
        result=b;
    }
    return result;
}
node* getMiddle(node* head) {
    if (!head) return head;
    node *slow=head;
    node *fast=head->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* mergeSort(node* head) {
    if(!head|| !head->next)
        return head;
    node* middle=getMiddle(head);
    node* nextToMiddle=middle->next;
    middle->next=NULL;
    node* left=mergeSort(head);
    node* right=mergeSort(nextToMiddle);
    return merge(left,right);
}
node* nthFromEnd(node* head,int n) {
    node *first=head;
    node *second=head;
    for (int i=0;i<n;i++) {
        if (!first)
            return NULL;
        first=first->next;
    }
    while(first){
        first=first->next;
        second=second->next;
    }
    return second;
}
int main(){
    node *head=NULL;
    node *res=NULL;
    for(int i=0;i<5;i++)
        head=insert(head);
    print(head);
    printf("List after merge sort: ");
    res=mergeSort(head);
    print(res);
    res=nthFromEnd(head,3);
    printf("nth node from last (data): %d\n\n",res->data);
    return 0;
}