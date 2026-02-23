/*
30. Log Session a grocery store inventory where you can add, update, or remove items using a file.
Input: Add item: Milk, 2 litres, Rs.40
Output: Inventory file now includes the new item
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct grocery
{
    char name[20];
    float quantity;
    int cost;
    struct grocery *next;
}item_t;
item_t* add_item(item_t *head,char *filename){
    item_t *new=NULL;
    FILE *fp;
    new=calloc(1,sizeof(item_t));
    printf("Enter item name:");
    scanf("%s",new->name);
    getchar();
    printf("Enter quantity:");
    scanf("%f",&new->quantity);
    getchar();
    printf("Enter cost of item:");
    scanf("%d",&new->cost);
    if(head==NULL) head=new;
    else{
        item_t *temp=head;
        while (temp->next)
            temp=temp->next;
        temp->next=new;
    }
    fp=fopen(filename,"a");
    if(fp==NULL){
        printf("No such file\n");
        return head;
    }
    fprintf(fp,"%-20s   %.2f   %d\n",new->name,new->quantity,new->cost);
    fclose(fp);
    return head;
}
void update(item_t* head){
    char name[20];
    int flag=1;
    printf("Enter name:");
    scanf("%s",name);
    FILE *fp;
    item_t *temp;
    if(head==NULL){
        printf("No items present in inventory to update\nadd items first\n");
        return;
    }
    temp=head;
    while (temp)
    {
        if(strcmp(name,temp->name)==0){
            flag=0;
            break;
        }
        temp=temp->next;
    }
    if(flag) printf("No such item in the inventory\n");
    else{
        printf("current quantity:%.2f\ncurrent cost:%d\n",temp->quantity,temp->cost);
        printf("Enter new quantity:");
        scanf("%f",&temp->quantity);
        printf("Enter new cost:");
        scanf("%d",&temp->cost);
    }
    if(!flag){
        fp=fopen("inventory.log","w");
        temp=head;
        while (temp){
            fprintf(fp,"%-20s   %.2f   %d\n",temp->name,temp->quantity,temp->cost);
            temp=temp->next;
        }
        fclose(fp);
    }    
}

item_t *remove_item(item_t* head){
    char name[20];
    if(head==NULL){
        printf("Inventory is empty\n");
        return NULL;
    }
    FILE *fp;
    item_t *temp,*prev;
    int flag=1;
    printf("Enter name to delete:");
    scanf("%s",name);
    temp=head;
    while (temp!=NULL)
    {
        if(strcmp(name,temp->name)==0){
            flag=0;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    if(flag){
        printf("No such intem in inventory\n");
        return head;
    }
    else{
        prev->next=temp->next;
        free(temp);
    }
    fp=fopen("inventory.log","w");
    temp=head;
    while (temp){
        fprintf(fp,"%-20s   %.2f   %d\n",temp->name,temp->quantity,temp->cost);
        temp=temp->next;
    }
    fclose(fp);
    return head;    
}
int main(){
    item_t *head=NULL;
    head=add_item(head,"inventory.log");
    head=add_item(head,"inventory.log");
    update(head);
    remove_item(head);
    return 0;
}
