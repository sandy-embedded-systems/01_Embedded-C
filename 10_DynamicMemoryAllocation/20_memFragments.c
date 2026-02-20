/*
Exercise 20: Simulate Memory Fragmentation
Goal: Understand fragmentation with sequential malloc and free.

Activity:

Allocate multiple memory blocks of varying sizes.
Free some in between.
Allocate a new block that fits only in fragmented space.
Observe behavior.
Free all at the end.
*/

#include<stdio.h>
#include<stdlib.h>
static int *arr[50];
void test_framgmentaion(void){
    int i,size;
    for(i=0;i<50;i++){
        arr[i]=malloc(rand()%1024+1024);
        if(arr[i]==NULL){
            printf("Memory allocaiton failed at index:%d\n",i);
            return;
        }
        else size=i;
    }
    printf("Memory allocated for %d\n",size);
    for(int i=0;i<size;i++)
        free(arr[i]);
    return;
}
int main(){
    test_framgmentaion();
    return 0;
}