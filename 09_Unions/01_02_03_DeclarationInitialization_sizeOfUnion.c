/*
1. Union Declaration and Initialization
Declare a union named Data with an int, a float, and a char array of size 20.
Write a program to initialize and print each member, one after the other. Observe and explain the output.

2.Size of Union
Write a program to declare a union containing an int, a double, and a char.
Print the size of this union using sizeof. Compare the result with the size of a structure having the 
same members.

3.Accessing Union Members
Using the union from exercise 1, assign values to more than one member at a time and print all members.
Observe which value is retained and explain why.
*/

#include<stdio.h>
union Data{
    int ui;
    double ud;
    char uc;
};
struct s
{
    int si;
    double sd;
    char sc;
};
void init_print(void){
    union Data test1={97};
    printf("%d %f %c\n\n",test1.ui,test1.ud,test1.uc);
}
void sizeCmp(void){
    struct s s_data;
    union Data u_data;
    printf("sizeof union:%ld\nsizeof structure:%ld\n\n",sizeof(u_data),sizeof(s_data));
}
void access_union(void){
    union Data u_data;
    u_data.ui=1024;
    u_data.uc='a';
    printf("%d %f %c\n\n",u_data.ui,u_data.ud,u_data.uc);
}
int main()
{
    init_print();
    sizeCmp();
    access_union();
    return 0;
}


