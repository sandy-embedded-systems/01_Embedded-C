/*
6. Variadic Average Function Challenge

Description
Write a C program to find the average of a variable number of doubles passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h to process double arguments and calculate their mean.

Sample Input & Output
Function call:
average(4, 10.5, 30.2, 40.1, 20.6)
Output:
The average is: 25.350000

Explanation
The first argument is the count of double values, followed by the values. The average is computed and returned.


7. Variadic printf() Implementation Challenge

Description
Write a C program to implement a simple printf() function using variadic functions.

Key Concept: Use stdarg.h to accept a format string and variable arguments; print accordingly (simplified version).

Sample Input & Output
Function call:
my_printf(3, 10, 20, 30)
Output:
The values are: 10 20 30

Explanation
The first argument is the count of values to print, followed by those values. All are printed in sequence.


8. Variadic Sorting Function Challenge

Description
Write a C program to sort a variable number of integers passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h to gather all integers, copy them to an array, sort, and print.

Sample Input & Output
Function calls:
sort_numbers(5, 9, 5, 7, 1, 3) → Output: 1 3 5 7 9
sort_numbers(3, 1, -2, 0) → Output: -2 0 1
 
Explanation
The first argument is the count of integers, followed by their values. The function sorts and prints them.
*/

#include<stdio.h>
#include<stdarg.h>

/* Variadic Average Function Challenge */
float average(int n,...){
    if(n<=0) return 0.0;
    va_list arguments;
    va_start(arguments,n);
    int total=0;
    for(int i=0;i<n;i++){
        total+=va_arg(arguments,int);
    }
    va_end(arguments);
    return (float)(total/n);
}

/* Variadic printf() Implementation Challenge */
int my_printf(int n,...){
    va_list args;
    va_start(args,n);
    printf("The values are:");
    int cnt=0;
    for(int i=0;i<n;i++){
        printf("%d ",va_arg(args,int));
        cnt++;
    }
    va_end(args);
    printf("\n");
    return cnt;
}

/* Variadic Sorting Function Challenge */
void sort_nums(int n,...){
    int arr[n];
    va_list arguments;
    va_start(arguments,n);
    for(int i=0;i<n;i++){
        arr[i]=va_arg(arguments,int);
    }
    va_end(arguments);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                arr[j]^=arr[j+1]^=arr[j]^=arr[j+1];
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return;
}

int main(){
    printf("%.2f\n",average(5,1,2,3,"hello",5));
    my_printf(4,1,2,3,4);
    sort_nums(5,9,67,28,5,3);
}