/*
17. Array of Function Pointers in a Structure
Define a structure (e.g., Calculator) that contains an array of function pointers for operations
 (add, subtract,multiply).
Instantiate the structure and use it to call the various operations on input values,
demonstrating how the structure can perform different calculations.

18. Replace Switch-Case with Function Pointer Table
Simulate a command-based application where each command is represented by a number.
Instead of using a large switch-case block to handle commands, create a function pointer table.
Use the input command number as an index to call the corresponding handler function via 
the function pointer table
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* Function Pointers in a Structure */
typedef int (*operation_t)(int,int);
int add(int a,int b){
    return a+b;
}
int subtract(int a,int b){
    return a-b;
}
int multiply(int a,int b){
    return a*b;
}

typedef struct  Calculator{
    operation_t addtion,subtraction,multiplication;
}cal;

 void struct_init(cal *obj){
    obj->addtion=add;
    obj->subtraction=subtract;
    obj->multiplication=multiply;
 }
 void user_interface_1(void){
    int a,b,choice;
    cal obj;
    struct_init(&obj);
    printf("Enter a:");
    scanf("%d",&a);
    printf("Enter b:");
    scanf("%d",&b);
    printf("%d + %d = %d\n%d - %d:%d\n",a,b,obj.addtion(a,b),a,b,obj.subtraction(a,b));
    printf("%d * %d = %d\n",a,b,obj.multiplication(a,b));
    return;
 }

 /* Replace Switch-Case with Function Pointer Table */
 typedef void (*func_ptr_table)(void);
void ls_fun(void){
    printf("ls command is executing\n");
}
void cd_fun(void){
    printf("cd command is executing\n");
}
void mkdir_fun(void){
    printf("mkdir is executing\n");
}
void pwd_fun(void){
    printf("pwd command is executing\n");
}
void clear_fun(void){
    printf("clear command is executing\n");
}
int getIndex(char *cmd){
    if(strcmp(cmd,"ls")==0) return 0;
    else if(strcmp(cmd,"cd")==0) return 1;
    else if(strcmp(cmd,"mkdir")==0) return 2;
    else if(strcmp(cmd,"pwd")==0) return 3;
    else if(strcmp(cmd,"clear")==0) return 4;
    else{
        printf("Invalid Command\n");
        exit(0);
    }
}
 void simulate_cmds(void){
    char cmd[20];
    int idx;
    func_ptr_table Table[5]={ls_fun,cd_fun,mkdir_fun,pwd_fun,clear_fun};
    printf("____AVAILABLE COMMANDS___\nls\ncd\nmkdir\npwd\nclear\nsanthohs/01_embedded:~$");
    scanf("%s",cmd);
    idx=getIndex(cmd);
    Table[idx]();
 }
 int main(){
    user_interface_1();
    simulate_cmds();
    return 0;
 }