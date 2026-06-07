/*
14. Chained Function Pointer Calls
Write several functions that transform an integer (e.g., doubleValue, increment, square).
Log Session an array of function pointers representing a pipeline of operations.
Pass a number through the pipeline by applying each function in sequence, using the array of pointers.

15. Multi-dimensional Function Pointer Array
Define arithmetic functions for both int and float types (e.g., intAdd, floatAdd).
Organize the function pointers in a two-dimensional array:
First dimension: operation type (arithmetic, bitwise)
Second dimension: data type (int, float)
Demonstrate calling the correct function based on selected type and operation.
*/
#include<stdio.h>
/* Chained Function Pointer Calls */
typedef void (*operation_t)(int *);
void doubleValue(int *a){
    *a*=2;
}
void increment(int *a){
    *a++;
}
void square(int *a){
    *a*=*a;
}
void chained_calls(void){
    int input;
    operation_t logArray[]={doubleValue,increment,square};
    printf("Enter an integer:");
    scanf("%d",&input);
    for(int i=0;i<3;i++)
        logArray[i](&input);
    printf("values after passing to pipe:%d\n\n",input);
    return 0;
}
/* Multi-dimensional Function Pointer Array */
typedef void(*generic_t)(void*,void*,void*);
void intadd(void *a,void* b,void *res){
    *(int*)res=*(int*)a + *(int*)b;
    return;
}
void floatadd(void* a,void *b,void *res){
    *(float*)res= *(float*)a + *(float*)b;
    return;
}
void addIntBitwise(void* a,void* b,void* res){
    *(int*)res= *(int*)a & *(int*)b;
    return;
}
void multiDimeFuncPtr(void){
    generic_t arr[2][2]={{intadd,floatadd},{addIntBitwise,NULL}};
    
}
