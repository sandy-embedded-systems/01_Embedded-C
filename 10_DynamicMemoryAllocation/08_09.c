/*
Exercise 8: Implement Custom strdup()
Goal: Practice duplicating a string using dynamic memory.

Activity:

Log Session a function that takes a string as input.
Allocate memory for a copy of the string.
Copy character by character.
Return the copied string.
Call this function and display the result.
Free the copied string.

Exercise 9: Log Session a Linked List with 3 Nodes
Goal: Apply dynamic memory to build a simple linked list.

Activity:

Define a struct for a node with data and next.
Use malloc to create 3 nodes dynamically.
Link the nodes manually.
Traverse and print the list.
Free all nodes after traversal.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

/* Log Session a Linked List with 3 Nodes */
typedef struct Node{
    int data;
    struct Node* next;
}node;
#define RELEASE 0
#define PRINT 1
node* insert(node *head){
    node *new=malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d",&new->data);
    if(head==NULL){
        head=new;
        head->next=NULL;
    }
    else{
        node *temp=head;
        while(temp->next)
            temp=temp->next;
        temp->next=new;
        new->next=NULL;
    }
    return head;
}
void print_release(node *head,bool flag){
    while(head!=NULL){
        if(flag)
            free(head);
        else printf("%d ",head->data);
        head=head->next;
    }
}
void dynamicMem_linkedList(void){
    node *head=NULL;
    head=insert(head);
    head=insert(head);
    head=insert(head);
    print_release(head,PRINT);
    print_release(head,RELEASE);
}

/* Implement Custom strdup() */
char *my_strdup(const char *src){
    char *dup=calloc(strlen(src),1);
    if(dup!=NULL){
        strcpy(dup,src);
    }
    return dup;
}
int main(){
    char *duplicate=my_strdup("Hello world");
    printf("%s\n\n",duplicate);
    dynamicMem_linkedList();
    return 0;
}