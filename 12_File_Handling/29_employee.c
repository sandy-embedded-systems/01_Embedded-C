/*
Store employee details in a file and update them as needed.
Input: Add new employee: Name: John, Age: 25
Output: Employee added (info saved in file)
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Employee
{
    char name[30];
    int age;
    struct Employee *next;
}emp_t;
emp_t* add_employee(emp_t *head,char *filename){
    emp_t *new=NULL;
    FILE *fp;
    new=calloc(1,sizeof(emp_t));
    printf("Enter employee name:");
    scanf("%s",new->name);
    getchar();
    printf("Enter age of employee:");
    scanf("%d",&new->age);
    if(head==NULL) head=new;
    else{
        emp_t *temp=head;
        while (temp->next)
            temp=temp->next;
        temp->next=new;
    }
    fp=fopen(filename,"a");
    if(fp==NULL){
        printf("No such file\n");
        return head;
    }
    fprintf(fp,"%-20s     %d\n",new->name,new->age);
    fclose(fp);
    return head;
}
void update(emp_t* head){
    char name[30];
    int flag=1;
    printf("Enter name:");
    scanf("%s",name);
    FILE *fp;
    emp_t *temp;
    if(head==NULL){
        printf("No employees present in Record to update\nadd employees first\n");
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
    if(flag) printf("No such employee in the Record\n");
    else{
        printf("Updation possible:");
        printf("current age:%d\n",temp->age);
        printf("Enter new age:");
        scanf("%d",&temp->age);
    }
    if(!flag){
        fp=fopen("Record.log","w");
        temp=head;
        while (temp){
            fprintf(fp,"%-20s     %d\n",temp->name,temp->age);
            temp=temp->next;
        }
        fclose(fp);
    }    
}
int main()
{
    emp_t *head=NULL;
    head=add_employee(head,"Record.log");
    head=add_employee(head,"Record.log");
    head=add_employee(head,"Record.log");
    update(head);
    return 0;
}
