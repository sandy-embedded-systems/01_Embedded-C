/*
1. Structure vs Union in Embedded Systems
Goal
Understand how structures and unions differ in terms of memory layout, 
access, and use in embedded systems, particularly in data interpretation and memory saving.
Activity 
Define a structure and a union with three different data types (e.g., char, int, float).
Print the size of each and compare.
Write values to each member and observe the behavior.
Map the union onto a byte buffer and visualize how different types share memory.
Document a scenario where only one data type is valid at a time (e.g., packet command structure).
*/

#include<stdio.h>
struct StructType_t
{
    char ch;
    int num;
    float f;
};
union UnionType_t{
    int num;
    float f;
    char ch[4];
};
int main(){
    struct StructType_t sobj={'A',33,4.5};
    union UnionType_t uobj;
    uobj.num=0x12345678;
    printf("size of structure:%ld\nsize of Union:%ld\n",sizeof(sobj),sizeof(uobj));
    printf("memory share i union:\n");
    printf("%x %x %x %x\n",uobj.ch[0],uobj.ch[1],uobj.ch[2],uobj.ch[3]);
    return 0;
}
