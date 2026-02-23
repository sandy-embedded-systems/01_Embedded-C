/*
6. Partitioning with Dual Pivots
Question:
Write a C program to partition a linked list around a value x.

Sample data:
List: 3 5 7 5 9 2 1
x = 5

Expected output:
Reordered list: 3 2 1 5 7 5 9

7. Linked List Addition Variants
Question:
Write a C program to add two numbers represented by linked lists.

Sample data:
List 1: 8 7 9 2
List 2: 2 1 2 3

Expected output:
Result: 0 9 1 6 (carry handled)
*/
#include <stdio.h>
#include <stdlib.h>
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

/*Partitioning with Dual Pivots */
node* partition(node* head,int x){
    node *beforeStart=NULL,*beforeEnd=NULL;
    node *afterStart=NULL,*afterEnd=NULL;
    node *curr=head,*nextNode=NULL;
    while(curr){
        nextNode=curr->next;
        curr->next=NULL;
        if (curr->data<x){
            if(!beforeStart){
                beforeStart=beforeEnd=curr;
            }
            else{
                beforeEnd->next=curr;
                beforeEnd=curr;
            }
        }
        else{
            if(!afterStart){
                afterStart=afterEnd=curr;
            }
            else{
                afterEnd->next=curr;
                afterEnd=curr;
            }
        }
        curr=nextNode;
    }
    if(!beforeStart)
        return afterStart;
    beforeEnd->next=afterStart;
    return beforeStart;
}

/*Linked List Addition Variants */
node* addLists(node*l1,node*l2){
    node dummy;
    node *tail=&dummy,*newNode=NULL;
    dummy.next=NULL;
    int carry=0;
    while (l1 ||l2||carry){
        int sum=carry;
        if(l1){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->data;
            l2=l2->next;
        }
        newNode=malloc(sizeof(node));
        newNode->data=sum%10;
        newNode->next=NULL;
        carry=sum/10;
        tail->next=newNode;
        tail=newNode;
    }
    return dummy.next;
}
int main(){
    node *list1=NULL,*list2=NULL;
    printf("Enter list 1:\n");
    for(int i=0;i<5;i++)
        list1=insert(list1);
    printf("enter list 2:\n");
    for(int i=0;i<5;i++)
        list2=insert(list2);
    print(partition(list1,2));
    print(addLists(list1,list2));
    return 0;
}