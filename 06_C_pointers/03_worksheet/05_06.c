/*
5. Structure Padding and Packed Attributes
Goal: Analyze memory layout and size differences of structs with and without packing for peripheral registers.
Activity:
Define a structure containing char, int, and short fields:
struct PeripheralRegs {
  char status;
  int control;
  short error;
};
Print the total size of the structure and the offsets of each member using offsetof().
Redefine the structure with __attribute__((packed)) and compare sizes and offsets.

6. Function Pointer Arrays for Command Execution
Goal: Log Session an embedded command interface using an array of function pointers.
Activity: 
Declare three functions representing device operations:
void init(void);
void start(void);
void stop(void);
Log Session an array of function pointers referencing these functions:
void (*cmd_table[])(void) = {init, start, stop};
Use an index or enum value to invoke the appropriate function via the array.
*/
#include<stdio.h>
#include<stddef.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct PeripheralRegs{
    char status;
    int control;
    short error;
};
struct PeripheralRegs_1{
    char status;
    int control;
    short error;
}__attribute__((packed));
/* Structure Padding and Packed Attributes */
void strcute_members(void){
    printf("struct PheripheralRegs:\nTotail size:%ld",sizeof(struct PeripheralRegs));
    printf("Offsert of each member:\nstatus:%lu\n",offsetof(struct PeripheralRegs,status));
    printf("control:%lu\nerror:%lu\n\n",offsetof(struct PeripheralRegs,control),offsetof(struct PeripheralRegs,error));
    printf("struct PheripheralRegs_1:\nTotail size:%ld",sizeof(struct PeripheralRegs_1));
    printf("Offsert of each member:\nstatus:%lu\n",offsetof(struct PeripheralRegs_1,status));
    printf("control:%lu\nerror:%lu\n\n",offsetof(struct PeripheralRegs_1,control),offsetof(struct PeripheralRegs_1,error));
}

/* Function Pointer Arrays for Command Execution */
void init(void){
    printf("System init...processing..\ncompleted 1\n\n");
}
void start(void){
    printf("starting system...updating modules...\ncompleted 1\n\n");
}
void stop(void){
    printf("System halted/stoped...waiting for signal to start\n\n");
}
void (*cmd_table[])(void) = {init, start, stop};
int getIdx(char *cmd){
    if(strcmp("init",cmd)==0) return 0;
    else if(strcmp("start",cmd)==0) return 1;
    else if(strcmp("stop",cmd)==0) return 2;
    else exit(0);
}
void cmd_execusion(void){
    int idx;
    char cmd[20];
    while(true){
        printf("commands list:\n1.init\n2.start\n3.stop\n4.shutdown\nenter a command:");
        scanf("%s",cmd);
        if(strstr("initstartstopshutdown",cmd)){
            idx=getIdx(cmd);
            cmd_table[idx]();
        }
        else printf("Invalid command\nTry again...\n");
    }
}
int main(){
    strcute_members();
    cmd_execusion();
}