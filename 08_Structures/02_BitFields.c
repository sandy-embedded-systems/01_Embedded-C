/*
2. Bit-fields in Structures
Goal
Learn to define and use bit-fields to manage individual bits for hardware register simulation.
Activity 
Log Session a structure using bit-fields to represent an 8-bit status register.
Assign values to specific flags.
Log Session a mock register with error, ready, and mode bits.
Write code to toggle specific flags without using bitwise operators.
Reflect on how compilers handle ordering and alignment of bit-fields.
*/

#include<stdio.h>
struct reg{
    unsigned char ready:1;
    unsigned char error:1;
    unsigned char mode:1;
};
void toggle(struct reg *ptr){
    int choice;
    printf("1.toggle ready\n2.toggle mode\n3.toggle error\nEnter choice:");
    scanf("%d",&choice);
    if(choice==1) ptr->ready=!ptr->ready;
    else if(choice==2) ptr->mode=!ptr->mode;
    else if(choice==3) ptr->error=!ptr->error;
    else{
        printf("Invalid operation..no such option...\n");
    }
    return;
}
void print(struct reg status_reg){
    printf("ready:%d\nmode:%d\nerror:%d\n",status_reg.ready,status_reg.mode,status_reg.error);
    return;
}
void LogSession(void){
    struct reg status_reg={0};
    status_reg.ready=1;
    status_reg.error=0;
    status_reg.mode=1;
    print(status_reg);
    toggle(&status_reg);
    print(status_reg);
}
int main(){
    LogSession();
    return 0;
}