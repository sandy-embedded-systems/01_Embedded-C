/*
7. Dangling Pointer Scenario
Goal: Identify potential risks and behavior of dangling pointers in embedded dynamic memory management.
Activity:
Write a function that allocates a block of memory dynamically using malloc() and returns the pointer:
int *allocate_buffer(void) {
  int *buf = (int *)malloc(10 * sizeof(int));
  return buf;
}
In the calling context, free the memory pointed to and then try to access it via the original pointer.
Use debug prints or debugger to observe system behavior.

8. Dynamic Allocation of 2D Register Block
Goal: Dynamically allocate and manage a two-dimensional register map for peripheral configuration.
Activity: 
Allocate memory for a 4x4 matrix of 32-bit registers using double pointers:
uint32_t **reg_block;
reg_block = malloc(rows * sizeof(uint32_t *));
for (int i = 0; i < rows; i++)
  reg_block[i] = malloc(cols * sizeof(uint32_t));
Initialize the matrix elements with example register values.
Print the matrix values via pointer dereferencing.
Free all allocated memory properly after use.
*/
#include<stdio.h>
#include<stdlib.h>
/* Dangling Pointer Scenario */
int *allocate_buffer(void) {
  int *buf = (int *)malloc(10 * sizeof(int));
  return buf;
}
void scenario(void){
    int *arr=NULL;
    arr=allocate_buffer();
    free(arr);
 /*  printf("%d\n",arr[0]); // since the allocated memory is already freed, now the
     arr pointer become dangling pointer because the allocated memory is no longer with this process */
}

/* Dynamic Allocation of 2D Register Block */
void dynamic2D(void){
    int **reg_blocks;
    int *ptr=NULL;
    reg_blocks=malloc(4*sizeof(int*));
    for(int i=0;i<4;i++){
        reg_blocks[i]=malloc(4*sizeof(int*));
        if(reg_blocks[i]==NULL) i--;
    }
    printf("Memory allocation for 4x4 2D array is completed:\nEnter elements:\n");
    for(int i=0;i<4;i++){
        prntf("Enter row %d:",i);
        for(int j=0;j<4;j++){
            scanf("%d",reg_blocks[i][j]);
        }
        printf("\n");
    }
    printf("The array:");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d ",reg_blocks[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
    dynamic2D();
    scenario();
}