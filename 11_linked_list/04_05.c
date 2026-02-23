/*
4. Copy with Random Pointers Challenges
Question:
Write a C program to create a deep copy of a singly linked list where each node has a random pointer.

Sample data:
List: 1 2 3 5 7
Random pointers: 1→3, 2→5, 3→7, 5→1, 7→3

Expected output:
New list with same data and random pointers correctly mapped.

5. Intersection Finder Variants
Question:
Write a C program to find the intersection point of two singly linked lists.

Sample data:
List A: 1 2 → 3 4
List B: 5 → 3 4
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *random;
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
/* Deep copy function */
node* copyList(node* head){
    if(!head) return NULL;
    node *curr=head,*copy;
    node *copyHead=NULL;
    while(curr){
        copy=malloc(sizeof(node));
        copy->data=curr->data;
        copy->next=curr->next;
        copy->random=NULL;
        curr->next=copy;
        curr=copy->next;
    }
    curr=head;
    while(curr){
        if(curr->random)
            curr->next->random=curr->random->next;
        curr=curr->next->next;
    }
    curr=head;
    copyHead=head->next;
    while(curr){
        copy=curr->next;
        curr->next=copy->next;
        if(copy->next)
            copy->next=copy->next->next;
        curr=curr->next;
    }
    return copyHead;
}

/* Intersection Finder Variants */
node* getIntersection(node* headA,node* headB){
    if (!headA ||!headB) return NULL;
    node *p1=headA;
    node *p2=headB;
    while(p1!=p2){
        p1=(p1==NULL)? headB: p1->next;
        p2=(p2==NULL)? headA : p2->next;
    }
    return p1;
}
int main(){
    node *list1=NULL,*list2=NULL;
    printf("Enter list 1:\n");
    for(int i=0;i<5;i++)
        list1=insert(list1);
    printf("enter list 2:\n");
    for(int i=0;i<5;i++)
        list2=insert(list2);
    copyList(list1);
    print(list1);
    node*p=getIntersection(list1,list2);
    if(p==NULL) printf("No intersection\n");
    else printf("\n\nIntersection found at node with data:%d\n",p->data);
}