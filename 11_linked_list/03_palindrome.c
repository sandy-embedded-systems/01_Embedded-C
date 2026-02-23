/*
3. Palindrome Check Variants
Question:
Write a C program to check if a singly linked list is a palindrome.

Sample data:
List: 1 2 2 1

Expected output:
Linked list is a palindrome.

*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
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
node *reverse(node *head){
    node *prev=NULL,*cur=head,*next=NULL;
    while (cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}

void check_palindrome(node *head){
    if(head==NULL ||head->next==NULL){
        printf("Palindrome\n");
        return;
    }
    node *slow=head,*fast=head;
    node *second_half,*first_half=head;
    while (fast!=NULL &&fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }
    second_half=reverse(slow);
    while(second_half!=NULL){
        if(first_half->data!=second_half->data){
            printf("Not a palindrome\n");
            return;
        }
        first_half=first_half->next;
        second_half=second_half->next;
    }
    printf("palindrome\n");
    return;
}
int main(){
    node *head=NULL;
    for(int i=0;i<5;i++){
        head=insert(head);
    }
    print(head);
    check_palindrome(head);
    return 0;
}