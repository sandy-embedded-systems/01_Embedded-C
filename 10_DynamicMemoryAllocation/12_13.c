/*
Exercise 12: Track Frequency of Elements
Goal: Use calloc for zero-initialized counting.

Activity:

Allocate an integer array of size 100 using calloc.
Accept n numbers between 0 and 99.
Increment the value at each index to count frequency.
Display the frequencies.
Free the memory.

Exercise 13: Memory Leak Simulation
Goal: Understand what a memory leak is.

Activity:

Allocate memory using malloc and assign values.
Intentionally skip free().
Run the program with tools like valgrind to observe the leak.
Fix the leak by adding proper free().
*/

#include<stdio.h>
#include<stdlib.h>

void freqency(void){
    int n,num, *arr=calloc(100,sizeof(int));
    if(arr==NULL){
        printf("memory allocation failed\n\n");
        return;
    }
    printf("Enter no.of inputs:");
    scanf("%d",&n);
    if(n<=0 || n>100){
        printf("Invalid size choosen\n\n");
        return;
    }
    for(int i=0;i<n;i++){
        printf("enter input:");
        scanf("%d",&num);
        arr[num]++;
    }
    printf("frequency of each element:\n");
    for(int i=0;i<100;i++){
        if(arr[i]!=0) printf("%d :%d\n",i,arr[i]);
    }
    free(arr);
}

/* Memory Leak Simulation */
void mem_leak(void){
    char *buff=calloc(1024,1);
    //free(buff);
    return;
}
int main(){
    freqency();
    mem_leak();
    return 0;
}