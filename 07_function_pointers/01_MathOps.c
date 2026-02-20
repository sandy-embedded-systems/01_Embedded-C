/*
1.Mathematical Operations with Function Pointers
Log Session four simple mathematical functions (add, subtract, multiply, divide) 
that accept two integer arguments and return an integer.
Use a single function pointer to dynamically select and execute one of these operations based on user input.
*/

#include<stdio.h>
int add(int a,int b){
    return a+b;
}
int subtract(int a,int b){
    return a-b;
}
int multiply(int a,int b){
    return a*b;
}
int divide(int a,int b){
    return a/b;
}
void calculate(void){
    int (*func_ptr)(int,int);
    int op1,op2;
    char op;
    printf("Enter value1:");
    scanf("%d",&op1);
    printf("Enter value2:");
    scanf("%d",&op2);
    while((op=getchar())!='\n');
    printf("Enter symbold(+,-,*,/):");
    scanf("%c",&op);
    switch(op){
        case '+':func_ptr=add;
                 printf("result=%d\n",func_ptr(op1,op2));
                 break;
        case '-':func_ptr=subtract;
                 printf("result=%d\n",func_ptr(op1,op2));
                 break;
        case '*':func_ptr=multiply;
                 printf("result=%d\n",func_ptr(op1,op2));
                 break;
        case '/':func_ptr=divide;
                 printf("result=%d\n",func_ptr(op1,op2));
                 break;
        default:printf("No such operation\n");
    }
}
int main(){
    calculate();
}