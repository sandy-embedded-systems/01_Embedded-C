/*
11. Memory Layout of Structures
Goal
Analyze the internal memory layout of structures, including padding, alignment, and impact on memory optimization.

Activity
Define a structure and use sizeof() to observe unexpected sizes.
Use different data type orderings and compare structure size.
Simulate structure layout for peripheral memory mapping.
Apply structure packing using #pragma and compare memory efficiency.
*/

#include<stdio.h>
#include<stdlib.h>
#define SETBIT(PHRI_REG,bit) (PHRI_REG|=(1<<bit))
#define CLEARBIT(PHRI_REG,bit) (PHRI_REG&=~(1<<bit))
#define TOGGLEBIT(PHRI_REG,bit) (PHRI_REG^=(1<<bit))

struct student_1{
    char ch;
    int id;
    short int marks;
};
struct student_2{
    int id;
    short int marks;
    char ch;
};

typedef struct Pheripheral{
    volatile unsigned int CONTROL;
    volatile unsigned int STAUTS;
    volatile unsigned int DATA;
}rccType_t;
void simulate(void){
    rccType_t *RCC=(rccType_t*)calloc(1,sizeof(rccType_t));
    SETBIT(RCC->CONTROL,2);
    RCC->DATA=44;
    if(!(RCC->STAUTS& 0x01)){
        printf("Status: check ... 1\n");
        return;
    }
    free(RCC);
}
int main(){
    struct student_1 s1;
    struct student_2 s2;
    printf("different data type orderings and sizes:\n");
    printf("student_1:%ld\nstudent_2:%ld\n\n",sizeof(s1),sizeof(s2));
    simulate();
    return 0;
}