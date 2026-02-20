/*
8. Structures and Functions
Goal
Learn how to pass structures to and return structures from functions and understand the trade-offs between pass-by-value and pass-by-reference.

Activity
Write a function that takes a structure as a value argument and modifies it.
Write a function that takes a pointer to structure and modifies it.
Return a structure from a function and print its values.
Measure memory usage and performance difference between pass-by-value and reference.
*/
#include<stdio.h>
typedef struct student{
    int id;
    char name[30];
    float marks;
}StructType_t;
void structCallByValue(StructType_t obj){
    float value=obj.marks;
    printf("In call by value:\n");
    obj.marks=45.6;
    printf("Marsk modified:%.2f to %.2f\n",value,obj.marks);
    return;
}
void structCallByAddress(StructType_t * ptr){
    int value=ptr->id;
    printf("In call by address\n");
    ptr->id=1122;
    printf("Id modifies:%d to %d\n",value,ptr->id);
    return;
}
StructType_t structAsReturn(void){
    StructType_t temp={2134,"santhosh",75.34};
    return temp;
}
int main(){
    StructType_t obj={2321,"BitSilica",87.56};
    printf("Before CallByValue: %d  %s %.2f\n",obj.id,obj.name,obj.marks);
    structCallByValue(obj);
    printf("After CallByValue: %d  %s %.2f\n",obj.id,obj.name,obj.marks);
    printf("Before CallByAddress: %d  %s %.2f\n",obj.id,obj.name,obj.marks);
    structCallByAddress(&obj);
    printf("After CallByAddress: %d  %s %.2f\n",obj.id,obj.name,obj.marks);
    obj=structAsReturn();
    printf("Before CallByValue: %d  %s %.2f\n",obj.id,obj.name,obj.marks);
    return 0; 
}