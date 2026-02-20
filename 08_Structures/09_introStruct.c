/*
9. Introduction to Structures in C
Goal
Grasp the basic concept of structures in C, including their need, syntax, and difference from arrays and unions.

Activity
Define a simple structure with multiple data types.
Compare it with an array and a union with similar members.
Initialize the structure in different ways and print values.
Analyze why structures are preferred in peripheral register grouping.
*/

#include<stdio.h>
typedef struct
{
    char ch;
    int num;
    float marks;
}StructType_t;

void print(StructType_t obj){
    printf("%c %d %.2f\n\n",obj.ch,obj.num,obj.marks);
}
int main(){
    StructType_t s1={'a',123,4.5}; //direct initialization
    StructType_t s2={.marks=5.4,.num=345,.ch='b'}; // designated initialization
    StructType_t s3=s2; // shallow copy initialization
    print(s1);
    print(s2);
    print(s3);
    return 0;
    
}