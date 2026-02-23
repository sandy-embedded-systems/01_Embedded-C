/*
12. Merging K Sorted Lists Challenges
Question:
Write a C program to merge K sorted linked lists.

Sample data:
List-1: 10 20 50
List-2: 30 40 60
List-3: 10 70 100

Expected output:
Merged list: 10 10 20 30 40 50 60 70 100

13. Reordering by Parity Challenges
Question:
Write a C program to place all even-numbered nodes after odd-numbered nodes.

Sample data:
List: 1 2 3 4 5 6

Expected output:
Reordered list: 1 3 5 2 4 6
*/
#include<stdio.h>
#include<stdlib.h>
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

/* Merging K Sorted Lists Challenges */
node* mergeTwo(node* a,node* b) {
    if (!a) return b;
    if (!b) return a;
    node *result=NULL;
    if(a->data<=b->data){
        result=a;
        result->next=mergeTwo(a->next,b);
    }
    else{
        result=b;
        result->next=mergeTwo(a,b->next);
    }
    return result;
}
node* mergeK(node* lists[],int left,int right){
    if (left>right)
        return NULL;
    if (left==right)
        return lists[left];
    int mid=(left+right)/2;
    node* l1=mergeK(lists,left,mid);
    node* l2=mergeK(lists, mid+1,right);
    return mergeTwo(l1, l2);
}

/* Reordering by Parity Challenges */
node* oddEvenList(node* head){
    if(!head|| !head->next)
        return head;
    node *odd=head;
    node *even=head->next;
    node *evenHead=even;
    while(even && even->next){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}
void Task(int n){
    node *lists[n],*result=NULL;
    for(int i=0;i<n;i++){
        printf("\nEnter list:%d\n",i);
        for(int j=0;j<5;j++)
            lists[i]=insert(lists[i]);
    }
    result=mergeK(lists,0,n-1);
    print(result);
    oddEvenList(lists[0]);
    return;
}
int main(){
    int lists;
    printf("Enter no.of lists:");
    scanf("%d",&lists);
    if(lists<=0){
        printf("Invalid input\n\n");
        return 0;
    }
    Task(lists);
}