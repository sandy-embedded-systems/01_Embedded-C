/*
8. List Rotation Challenges
Question:
Write a C program to rotate a linked list to the right by k places.

Sample data:
List: 1 3 4 7 9
k = 2

Expected output:
Rotated list: 4 7 9 1 3

9. Kth Node Swapping Variants
Question:
Write a C program to swap Kth node from beginning and end.

Sample data:
List: 1 2 3 4 5
k = 2
Expected output:
Swapped list: 1 4 3 2 5
*/

#include <stdio.h>
#include <stdlib.h>
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

/* List Rotation Challenges*/
node* rotateRight(node* head,int k){
    if(!head|| !head->next ||k==0)
        return head;
    node *curr=head,*newHead=NULL;;
    int length=1,steps;
    while(curr->next){
        curr=curr->next;
        length++;
    }
    curr->next=head;
    k=k%length;
    steps=length-k;
    curr=head;
    for(int i=1;i<steps;i++)
        curr=curr->next;
    newHead=curr->next;
    curr->next=NULL;
    return newHead;
}

/* Kth Node Swapping Variants */
node* swapKth(node* head,int k) {
    if (!head)
        return head;
    int n=0;
    node *curr=head;
    node *x,*x_prev, *y,*y_prev,*temp;
    while(curr){
        n++;
        curr=curr->next;
    }
    if(k>n)
        return head;
    if(2*k-1==n)
        return head;
    x=head;
    x_prev=NULL;
    for(int i=1;i<k;i++){
        x_prev=x;
        x=x->next;
    }
    y=head;
    y_prev=NULL;
    for(int i=1;i<n-k+1;i++) {
        y_prev=y;
        y=y->next;
    }
    if(x_prev)
        x_prev->next=y;
    if(y_prev)
        y_prev->next=x;
    temp=x->next;
    x->next=y->next;
    y->next=temp;
    if(k==1)
        head=y;
    if(k==n)
        head=x;
    return head;
}
int main(){
    node *head=NULL;
    for(int i=0;i<5;i++){
        head=insert(head);
    }
    head=rotateRight(head,2);
    printf("list after right rotation: ");
    print(head);
    printf("List after swap: ");
    head=swapKth(head,3);
    print(head);
    return 0;
}