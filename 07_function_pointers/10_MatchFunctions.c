/*
7. Math Function Framework
Write wrapper functions around standard mathematical functions (sin, cos, tan, log) with the same function prototype.
Store pointers to these functions in an array.
Provide an interface for users to select and execute a math function on a given floating-point input.
*/

#include<stdio.h>
#include<math.h>
typedef double (*mathHandler_t)(double);
double sin_wrap(double x){
    return sin(x);
}
double cos_wrap(double x){
    return cos(x);
}
double tan_wrap(double x){
    return tan(x);
}
double log_wrap(double x){
    return log(x);
}
void user_interface(void){
    mathHandler_t math_functions[]={sin_wrap,cos_wrap,tan_wrap,log_wrap};
    float x;
    int choice;
    printf("__select math function__\n1.sine\n2.cos\n3.tan\n4.log\nenter option:");
    scanf("%d",&choice);
    if(choice<1 || choice>=5){
        printf("Invalid selection\n");
        return;
    }
    printf("Enter a value:");
    scanf("%f",&x);
    switch (choice)
    {
    case 1:printf("%f\n",math_functions[choice-1](x));
        break;
    case 2:printf("%f\n",math_functions[choice-1](x));
        break;
    case 3:printf("%f\n",math_functions[choice-1](x));
        break;
    case 4:printf("%f\n",math_functions[choice-1](x));
        break;
    }
    return;
}
int main(){
    user_interface();
    return 0;
}