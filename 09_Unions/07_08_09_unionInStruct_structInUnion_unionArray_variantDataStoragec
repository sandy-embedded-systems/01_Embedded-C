/*7.Unions in Structures
Log Session a structure Student with a union inside it that can hold either an int roll_number or a char id[10].
Add a member char type to indicate which member is active.
Write functions to initialize and display the data for both types of students.

8.Structure Inside a Union
Define a union that contains a structure (for example, struct { int x, y; }) and an int.
Write a program to set and access the structure members through the union.

9.Union Array
Declare an array of unions, each holding an int, a float, or a char.
Write a program to assign values of different types to each element and display them. Observe any issues.

10.Use Case – Variant Data Storage
Design a simple employee record system using a structure with a union that can store either salary (float) or 
hourly wage (float), depending on employee type.
Add code to input and print details for a list of employees.
*/

#include<stdio.h>
/* union inside structure */
#define ROLL_ACTIVE 1
#define ID_ACTIVE 2
typedef struct sample_data_type{
    union student{
        int roll_num;
        char id[10];
    }st;
    char active;
}StructType_t;
void init(StructType_t *ptr){
    int choice;
    printf("Enter which want to active:\n1.roll num\n2.id\nselect choice:");
    scanf("%d",&choice);
    if(choice==ROLL_ACTIVE){
        printf("Enter roll num:");
        scanf("%d",&choice);
        ptr->st.roll_num=choice;
        ptr->active=ROLL_ACTIVE;
    }
    else if(choice==ID_ACTIVE){
        ptr->active=ID_ACTIVE;
        printf("Enter id:");
        scanf("%s",ptr->st.id);
    }
    else{
        printf("No such option");
        return;
    }
}
void print(StructType_t p){
    printf("%d %s\n",p.st.roll_num,p.st.id);
}
void UnionInStruct(void){
    StructType_t student1;
    init(&student1);
    print(student1);
    return;
}
/* structure inside union */
union MyUnion
{
    struct
    {
        int x;
        int y;
    } point;
    int number;
};
void set_access(void){
    union MyUnion u;
    u.point.x=10;
    u.point.y=20;
    printf("Structure values:\n");
    printf("x=%d\n",u.point.x);
    printf("y=%d\n",u.point.y);
    u.number=100;
    printf("\nAfter assigning number=100\n");
    printf("number=%d\n",u.number);
    printf("x=%d\n",u.point.x);
    printf("y=%d\n",u.point.y);
    printf("\nNotice structure values changed!\n");
}

/*Union array*/
union Data
{
    int i;
    float f;
    char c;
};
void UnionArray(void){
    union Data arr[3];
    arr[0].i=50;
    arr[1].f=3.14f;
    arr[2].c='A';
    printf("arr[0] int =%d\n",arr[0].i);
    printf("arr[1] float=%.2f\n",arr[1].f);
    printf("arr[2] char =%c\n",arr[2].c);
    printf("\nNow overwrite arr[0] with float\n");
    arr[0].f=9.8f;
    printf("arr[0] as float =%.2f\n",arr[0].f);
    printf("arr[0] as int =%d\n",arr[0].i);
    printf("\nNotice the value changed because union shares memory.\n");
}
int main(){
    UnionInStruct();
    set_access();
    UnionArray();
    return 0;
}
