/*
10. Use Case – Variant Data Storage
Design a simple employee record system using a structure with a union that can store either salary (float) or hourly wage (float), depending on employee type.
Add code to input and print details for a list of employees.
*/

#include <stdio.h>
#define MAX 5
struct Employee
{
    int id;
    char name[50];
    int type;
    union
    {
        float salary;
        float hourly_wage;
    } pay;
};
void print(struct Employee *emp,int n){
    int i;
    printf("\n___Employee Details___\n");
    for(i=0;i<n;i++)
    {
        printf("\nID: %d\n",emp[i].id);
        printf("Name: %s\n",emp[i].name);

        if(emp[i].type==1)
        {
            printf("Type: Full-time\n");
            printf("Salary:%.2f\n",emp[i].pay.salary);
        }
        else if(emp[i].type==2)
        {
            printf("Type: Part-time\n");
            printf("Hourly Wage:%.2f\n",emp[i].pay.hourly_wage);
        }
    }

}
int main()
{
    struct Employee emp[MAX];
    int n,i;
    printf("Enter number of employees (max %d):",MAX);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEmployee %d\n",i+1);
        printf("Enter ID:");
        scanf("%d",&emp[i].id);
        printf("Enter Name: ");
        scanf("%s",emp[i].name);
        printf("Enter Type (1=Full-time, 2=Part-time): ");
        scanf("%d",&emp[i].type);
        if(emp[i].type==1)
        {
            printf("Enter Monthly Salary: ");
            scanf("%f",&emp[i].pay.salary);
        }
        else if(emp[i].type==2)
        {
            printf("Enter Hourly Wage: ");
            scanf("%f",&emp[i].pay.hourly_wage);
        }
        else
        {
            printf("Invalid type!\n");
        }
    }
    print(emp,n);
    return 0;
}