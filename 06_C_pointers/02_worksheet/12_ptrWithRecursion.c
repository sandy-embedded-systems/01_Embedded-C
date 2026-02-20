/*
12. Pointer and Recursion
Goal: Use pointers within recursive functions to manipulate data structures or strings.

Activity:

Write a recursive function to reverse a string using pointers.
Implement a recursive traversal of a linked list using pointers.
Use recursion to perform operations such as summing elements of an array via pointer traversal.
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
node *addLast(node *head){
    node *new=NULL,*temp;
    new=(node*)calloc(1,sizeof(node));
    if(new==NULL){
        printf("ERROR:Memory allocation Failed\n");
        return head;
    }
    printf("Enter data:");
    scanf("%d",&new->data);
    if(head==NULL) head=new;
    else{
        temp=head;
        while(temp->next)
            temp=temp->next;
        temp->next=new;
    }
    return head;
}

/* sumof elements of array using recursion*/
int arraySum(int *p,int size){
    if(size==0) return 0;
    return *(p+size-1)+arraySum(p,size-1);
}

/* print list using recursion*/
void printList(node *head){
    if(head==NULL) return;
    printf("%d ",head->data);
    printList(head->next);
}
int main(){
    int arr[]={1,2,3,4,5};
    node *head=NULL;
    head=addLast(head);
    head=addLast(head);
    head=addLast(head);
    head=addLast(head);
    printf("%d\n",arraySum(arr,5));
    printf("The List:");
    printList(head);
}