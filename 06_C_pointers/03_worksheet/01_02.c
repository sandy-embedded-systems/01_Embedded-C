/*
1. Pointer and Array Behavior
Goal: Analyze how pointers and arrays differ in memory referencing and sizeof operations in embedded systems.
Declare an integer array with predefined elements:
int arr[5] = {10, 20, 30, 40, 50};
Declare an integer pointer and assign it to the array's base address:
int *ptr = arr;
Print the values of the array name, the pointer, and the address of the array.
Use sizeof() on the array and pointer and observe differences.
Access the elements via both array indexing and pointer arithmetic, and print them.

2. Accessing Multi-Dimensional Arrays with Pointers
Goal: Implement pointer arithmetic to traverse a 2D sensor data array efficiently without nested loops.
Activity:

Define a 3x3 integer matrix representing sensor readings:
int sensors[3][3] = {
  {100, 101, 102},
  {110, 111, 112},
  {120, 121, 122}
};
Assign a pointer to the first element of the matrix:
int *p = &sensors[0][0];
Use a single loop and pointer arithmetic to iterate over the matrix elements.
Print each sensor value accessed via the pointer.
*/

#include<stdio.h>
/* behaviour of array and pointer*/
void ptrVSarr(void){
    int arr[]={10,20,30,40,50};
    int *ptr=arr;
    printf("value in ptr:%p\nbase addr of arr:%p\n",ptr,arr);
    printf("sizeof arr:%ld\nsizeof ptr:%ld\n",sizeof(arr),sizeof(ptr));
    printf("arr(using indexing):");
    for(int i=0;i<5;i++)
        printf("%d",arr[i]);
    printf("\narr(using pointer arithmetic):");
    for(int i=0;i<5;i++)
        printf("%d",*(arr+i));
    return;
}

/* 2D-array print with single pointer*/
void multiDimentionalAccess(void){
    int cnt=0;
    int sensors[3][3] = {
  {100, 101, 102},
  {110, 111, 112},
  {120, 121, 122} };
  int *p=&sensors[0][0];
  for(int i=0;i<9;i++){
    printf("%d ",*p);
    cnt++;
    if(cnt==3){
        cnt=0;
        printf("\n");
    }
    p++;
  }
}
int main(){
    multiDimentionalAccess();
    ptrVSarr();
    
}