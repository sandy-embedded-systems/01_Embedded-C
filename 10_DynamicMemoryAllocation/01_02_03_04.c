/*
Exercise 1: Allocate Memory for an Integer
Goal: Understand how to allocate memory for a single variable using malloc.

Activity:

Log Session a pointer to an integer.
Use malloc to allocate memory for one integer.
Assign a value to that memory.
Print the value through the pointer.
Free the allocated memory.
Include NULL check after malloc.

Exercise 2: Allocate and Store a List of Integers
Goal: Practice allocating memory for an array of integers.

Activity:

Ask the user to enter the number of integers.
Allocate memory dynamically using malloc based on input.
Use a loop to take integer inputs into the allocated array.
Display the entered values.
Free the allocated memory.

Exercise 3: Zero-Initialize an Integer Array
Goal: Understand how calloc initializes memory.

Activity:

Ask the user for the number of elements.
Allocate memory using calloc.
Print the initial values (before user input).
Assign values, then display them.
Free the memory after use.

Exercise 4: Compare malloc and calloc
Goal: Learn the key difference between malloc and calloc.

Activity:

Allocate two arrays using malloc and calloc with the same size.
Print the default values in both arrays.
Use a loop for printing to understand initialization differences.
Free both arrays.
*/
#include<stdio.h>
#include<stdlib.h>

/* Allocate Memory for an Integer */
void mem_for_int(void){
    int *ptr=malloc(sizeof(int));
    if(ptr==NULL){
        printf("Memory allocation failed\n\n");
        return;
    }
    *ptr=30;
    printf("Value=%d\n\n",*ptr);
    free(ptr);
}
/* Allocate and Store a List of Integers */
void mem_for_arr(void){
    int *arr,n;
    printf("enter no.of ints:");
    scanf("%d",&n);
    if(n<=0){
        printf("array size not possible\n\n");
        return;
    }
    arr=malloc(n*sizeof(int));
    if(arr==NULL){
        printf("Memory allocation failed\n\n");
        return;
    }
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    printf("Entered elemets: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n\n");
    free(arr);
}

/* Zero-Initialize an Integer Array */
void mem_for_arr_0(void){
    int *arr,n;
    printf("enter no.of ints:");
    scanf("%d",&n);
    if(n<=0){
        printf("array size not possible\n\n");
        return;
    }
    arr=calloc(n,sizeof(int));
    if(arr==NULL){
        printf("Memory allocation failed\n\n");
        return;
    }
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    printf("Entered elemets: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n\n");
    free(arr);
}

void print(int *arr,int n){
    printf("Array: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n\n");
}
/* Compare malloc and calloc*/
void cmp_malloc_calloc(void){
    int *m_arr=malloc(5*sizeof(int));
    int *c_arr=calloc(5,sizeof(int));
    print(m_arr,5);
    print(c_arr,5);
    free(m_arr);
    free(c_arr);
    return;
}
int main(){
    mem_for_int();
    mem_for_arr();
    mem_for_arr_0();
    cmp_malloc_calloc();
    return 0;
}