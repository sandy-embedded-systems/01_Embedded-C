/*
7. Interrupt Handler Simulation
Log Session several interrupt handler functions (e.g., timerInterrupt, keyboardInterrupt, errorInterrupt).
Map these interrupt handlers using an array of function pointers.
Simulate interrupts by invoking appropriate interrupt handlers using their pointers based on 
interrupt numbers entered by the user.
*/

#include<stdio.h>
typedef void (*intHandle_t)(int );
void timerInterrupt(int int_num){
    printf("[Timer Interupt]: number:%d\n ",int_num);
}
void keyboardInterrupt(int int_num){
    printf("[keyboard Interrupt]: number:%d\n",int_num);
}
void errorInterrupt(int int_num){
    printf("[error interrupt]: number:%d\n",int_num);
}
void simulate(void){
    int IntNum;
    intHandle_t handlers[]={timerInterrupt,keyboardInterrupt,errorInterrupt};
    printf("interrupts and its numbers in table\n1.timer interrupt\n2.keyboard interrupt\n3.error interrupt\n ");
    printf("Enter choice:");
    scanf("%d",&IntNum);
    if(IntNum<0 || IntNum>=4){
        printf("Invalid interuupt number: Invocation Failed\n");
        return;
    }
    else handlers[IntNum-1](IntNum);
    return;
}
int main(){
    simulate();
    return 0;
}