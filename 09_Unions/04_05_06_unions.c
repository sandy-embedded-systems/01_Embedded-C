/*
4.Nested Union
Log Session a union called Number which contains an int and a nested union with a float and a char.
Write code to assign and access values from both the outer and inner union members.

5.Anonymous Union
Declare an anonymous union inside a structure.
Initialize and access its members without using a union name.
Demonstrate how this simplifies access in code.

6.Pointer to a Union
Write a program that defines a union called Sample with an int and a float.
Declare a pointer to the union. Assign values using the pointer and print the results.
*/

#include<stdio.h>
/* Nested unions */
typedef union data{
    float f;
    char ch;
}DataType_t;
typedef union n{
    int num;
    DataType_t data;
}Number;
void nestedUnion(void){
    Number num={.num=121};
    printf("inner uinon:\n%f %c\n",num.data.f,num.data.ch);
    printf("Ouuter union:%d\n",num.num);
}

/* Anonymous Union */
struct anonymous{
    int age;
    union{
        int id;
        char ch;
    };
};
void anonymusUnion(){
    struct anonymous s={.age=97};
    printf("Value given to struct mamber:%d\n",s.age);
    printf("values of anonymus union:\n");
    printf("%d %c\n",s.id,s.ch);
}

/* pointer to union */
typedef union data_base{
    int age;
    float sal;
}Sample;
void ptrToUnion(void){
    Sample data;
    Sample *ptr=&data;
    ptr->age=23;
    printf("%d %f\n\n",ptr->age,ptr->sal);
}
int main(){
    nestedUnion();
    anonymusUnion();
    ptrToUnion();
    return 0;
    
}