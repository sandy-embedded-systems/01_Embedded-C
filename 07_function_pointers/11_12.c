/*
11.Function Pointer as Return Value
Implement multiple arithmetic functions (add, subtract, multiply).
Write a function getOperation(char *name) that takes a string (like "add" or "subtract") and returns a pointer to the corresponding function.
Use this return value to perform the selected operation on user-provided numbers.

12.Function Pointer Array for String Operations
Implement several string manipulation functions (reverseString, toUpperCase, countVowels), each accepting a string argument.
Store these functions in an array of function pointers.
Prompt the user to choose an operation and apply it to their input string using the selected function pointer.
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
/* Function Pointer as Return Value */
typedef int (*operation_t)(int,int);
typedef void (*strOperatioin_t)(char*);
int add(int a,int b){
    return a+b;
}
int subtract(int a,int b){
    return a-b;
}
int multiply(int a,int b){
    return a*b;
}
operation_t getOperation(char *name){
    if(strcmp("add",name)==0) return add;
    else if(strcmp("subtract",name)==0) return subtract;
    else if(strcmp("multiply",name)==0) return multiply;
    else return NULL;
}
void user_interface_1(void){
    int a,b;
    operation_t func_ptr;
    char name[20];
    printf("Enter a:");
    scanf("%d",&a);
    printf("Enter b:");
    scanf("%d",&b);
    printf("Enter operation in text form(ex:add):");
    scanf("%s",name);
    func_ptr=getOperation(name);
    if(func_ptr==NULL){
        printf("No such operation\n");
        return;
    }
    else printf("Result=%d\n\n",func_ptr(a,b));
}

/* Function Pointer Array for String Operations */
void reverseString(char *str){
    for(int i=0,j=strlen(str)-1;i<j;i++,j--)
        *(str+i)^=*(str+j)^=*(str+i)^=*(str+j);
    return ;
}
void toUpperCase(char *str){
    for(int i=0;str[i];i++){
        if(islower(str[i])) str[i]^=32;
    }
}
bool isVowel(char ch){
    switch (ch)
    {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':return true;
    }
    return false;
}
void countOvwels(char *str){
    int cnt=0;
    for(int i=0;str[i];i++){
        if(isVowel(str[i])) cnt++;
    }
    printf("No.of vowels:%d\n\n",cnt);
}
void user_interface_2(void){
    strOperatioin_t arr[]={reverseString,toUpperCase,countOvwels};
    char str[50],ch;
    int choice;
    printf("Enter string:");
    while((ch=getchar())!='\n');
    scanf("%[^\n]s",str);
    printf("____MENU____\n1.reverse string\n2.convert to uppercase\n3.count vowels\nchoice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:arr[0](str);
               printf("reversed string:\n%s\n",str);
               break;
        case 2:arr[1](str);
               printf("string after conversion:\n%s\n",str);
               break;
        case 3:arr[2](str);
               break;
        default:printf("No such oprtion available\n");
    }
    return;
}

int main(){
    user_interface_1();
    user_interface_2();
    return 0;
}