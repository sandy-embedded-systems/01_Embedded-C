/*
4. Menu-driven Calculator Using Function Pointers
Implement mathematical operations (power, modulo, squareRoot) as separate functions.
Store these operation functions in a function pointer array.
Provide a user-interactive menu to select and execute the chosen operation on input values.

*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/* Menu-driven Calculator Using Function Pointers */
typedef double (*operation_t)(double,double);
double power(double value,double p){
    return pow(value,p);
}
double modulo(double a,double b){
    return fmod(a,b);
}
double squareRoot(double a, double b){
    (void)b;
    return sqrt(a);
}
void calculator(void)
{
    operation_t arr[]={power,modulo,squareRoot};
    double base,power;
    int choice;
    while(1){
        printf("......MENU......\n1.power\n2.modulo\n3.square root\n4.exit\nseclect choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter base:");
                   scanf("%lf",&base);
                   printf("Enter power:");
                   scanf("%lf",&power);
                   printf("result=%lf\n",arr[0](base,power));
                   break;
            case 2:printf("Enter base:");
                   scanf("%lf",&base);
                   printf("Enter power:");
                   scanf("%lf",&power);
                   printf("result=%lf\n",arr[1](base,power));
                   break;
            case 3:printf("Enter base:");
                   scanf("%lf",&base);
                   printf("result=%lf\n",arr[2](base,power));
                   break;
            case 4:exit(0);
            default:printf("Invalid choice\n");
        }
    }
}
int main(){
    calculator();
}