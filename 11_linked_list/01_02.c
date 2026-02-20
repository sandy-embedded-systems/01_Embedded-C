/*
1. Merge Sorted Lists Challenges
Question:
Write a C program to merge two sorted singly linked lists into a single sorted linked list.

Sample data:
List 1: 1 3 5 7
List 2: 2 4 6

Expected output:
Merged list: 1 2 3 4 5 6 7

2. Loop Detection Challenges
Question:
Write a C program to detect and remove a loop in a singly linked list.

Sample data:
List: 1 → 2 → 3 → 4 → 5 → (loop to 2)

Expected output:
Loop detected and removed.
List after removal: 1 2 3 4 5
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
/* merge sorted lists */
node *merge(node *l1,node *l2){
    node *head=NULL,*tail=NULL;
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->data<l2->data){
        head=l1;
        l1=l1->next;
    }
    else{
        head=l2;
        l2=l2->next;
    }
    tail=head;
    while(l1 && l2){
        if(l1->data<l2->data){
            tail->next=l1;
            l1=l1->next;
        }
        else{
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }
    if(l1) tail->next=l1;
    if(l2) tail->next=l2;
    return head;
}

/*Loop Detection Challenges*/
void detect_loop(node *head){
    node *slow=head;
    node *fast=head;
    int loop_found=0;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast){
            loop_found=1;
            break;
        }
    }
    if(!loop_found){
        printf("No loop detected.\n");
        return;
    }
    slow=head;
    if(slow==fast){
        while(fast->next!=slow)
            fast=fast->next;
    }
    else{
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
    }
    printf("Loop detected and removed.\n");
    fast->next=NULL;
    printf("List after loop removed: ");
    print(head);
}
int main(){
    node *l1=NULL,*l2=NULL,*head;
    for(int i=0;i<5;i++)
        l1=insert(l1);
    for(int i=0;i<5;i++)
        l1=insert(l1);
    head=merge(head,l1);
    print(head);
}


