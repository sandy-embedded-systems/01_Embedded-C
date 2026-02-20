/*
10. Structure Declaration and Initialization
Goal
Understand the proper way to declare and initialize structures using multiple techniques and best practices.

Activity
Declare structure variables globally, locally, and statically.
Use designated initializers for clarity.
Use typedef to create aliases for complex structures.
Discuss structure initialization in embedded register mapping.
*/

#include<stdio.h>
typedef struct employee_data_base{
    char name[30];
    int id;
    float exp;
}empType_t;

static empType_t e1;

void print(empType_t emp){
    printf("Name:%s\nid  :%d\nexp :%.2f\n\n",emp.name,emp.id,emp.exp);
}
void struct_exercise(void){
    empType_t obj={"abc",1203,2.3}; // direct initialization
    empType_t obj1={.exp=3.4,.name="xyz",.id=2212}; // designated initialization
    e1=obj1;
    print(obj);
    print(e1);
}
int main(){
    struct_exercise();
    return 0;
}

