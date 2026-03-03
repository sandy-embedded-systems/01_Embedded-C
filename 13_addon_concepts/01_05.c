/*
1. Variadic Sum Function Challenge

Description
Write a C program to compute the sum of any number of integers passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h macros (va_list, va_start, va_arg, va_end) to access a variable number of arguments.

Sample Input & Output
Function calls:
sum(3, 1, 2, 3) → Output: 6
sum(5, 1, 2, 3, 4, 5) → Output: 15
sum(3, -1, -2, -3) → Output: -6

Explanation
The first argument is the count of values, followed by that many integers. The function returns their sum.


2. Variadic Product Function Challenge

Description
Write a C program to compute the product of any number of integers passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h macros to process a variable number of integer arguments.

Sample Input & Output
Function calls:
product(3, 1, 2, 3) → Output: 6
product(4, 1, 2, 3, 4) → Output: 24
product(3, -1, -2, -3) → Output: -6

Explanation
The first argument is the count of values, followed by that many integers. The function returns their product.


3. Variadic Max-Min Function Challenge

Description
Write a C program to find the maximum and minimum values of a variable number of integers passed as arguments 
to a function using variadic functions.

Key Concept: Use stdarg.h to process each integer, compare and update max and min values.

Sample Input & Output
Function calls:
find_max_min(5, 3, 5, 9, 0, 7)
Output:
Maximum value: 9
Minimum value: 0

Explanation
The first argument is the count of integers, followed by the values. The function finds both maximum
 and minimum among them.


4. Variadic String Concatenation Challenge

Description
Write a C program to concatenate a variable number of strings passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h with const char* arguments; copy and concatenate each string into a buffer.

Sample Input & Output
Function call:
concat_strings(3, "BitLearn", ".", "Bitsilica")
Output:
Concatenate said strings: BitLearn.Bitsilica

Explanation
The first argument is the count of strings, followed by the strings to concatenate. All are joined in order.


5. Variadic Character Count Challenge

Description
Write a C program to count the number of characters in a variable number of strings passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h to access each string and strlen() to count their lengths.

Sample Input & Output
Function call:
count_characters(3, "BitLearn", ".", "Bitsilica")
Output:
The total number of characters is 17

Explanation
The first argument is the count of strings, followed by the strings. Their lengths are summed.

*/

#include<stdio.h>
#include<stdarg.h>
#include<string.h>

 /* Variadic Sum Function Challenge */
 int sum(int n,...){
    va_list args;
    va_start(args,n);
    int total=0;
    for(int i=0;i<n;i++){
        total+=va_arg(args,int);
    }
    va_end(args);
    return total;
 }

 /* Variadic Product Function Challenge */
 int product(int n,...){
    va_list arguments;
    va_start(arguments,n);
    int prod=1;
    for(int i=0;i<n;i++){
        prod*=va_arg(arguments,int);
    }
    va_end(arguments);
    return prod;
 }

/* Variadic Max-Min Function Challenge */
void min_max(int n,...){
    va_list args;
    va_start(args,n);
    int num=va_arg(args,int);
    int min=num,max=num;
    for(int i=1;i<n;i++){
        num=va_arg(args,int);
        if(num>max) max=num;
        if(num<min) min=num;
    }
    va_end(args);
    printf("Minimum=%d\nMaximum=%d\n",min,max);
    return;
}
 /* Variadic String Concatenation Challenge */
 void concatinate(int n,...){
    va_list args;
    va_start(args,n);
    char buff[256];
    strcpy(buff,va_arg(args,char*));
    for(int i=1;i<n;i++){
        strcat(buff,va_arg(args,char*));
    }
    printf("%s\n",buff);
    va_end(args);
    return;
 }

/* Variadic Character Count Challenge */
unsigned int char_count(int n,...){
    va_list args;
    va_start(args,n);
    unsigned int count=0;
    for(int i=0;i<n;i++){
        count+=strlen(va_arg(args,char*));
    }
    va_end(args);
    return count;
}

int main(){
    printf("%d\n",sum(5,1,2,3,4,5));
    printf("%d\n",product(5,1,2,3,4,5));
    printf("%u\n",char_count(3,"Hello","hi","H"));
    concatinate(3,"Hello",".","World");
    min_max(4,1,2,3,4);

}