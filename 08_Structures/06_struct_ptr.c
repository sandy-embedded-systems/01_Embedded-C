/*
6. Structure Pointers and Memory Access
Goal
Understand the use of pointers to structures for efficient memory access and how to use the arrow operator for member access.

Activity
Declare a pointer to a structure and allocate memory using malloc().
Use arrow operator to assign and print structure member values.
Simulate memory-mapped peripheral access using structure pointers.
Illustrate how structure pointers simplify code in register programming.
*/

#include<stdio.h>
#include<stdlib.h>
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
    simulate();
    return 0;
}
