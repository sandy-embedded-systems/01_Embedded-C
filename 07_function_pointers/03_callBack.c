/*
3.Callback Function Array Processing
Define a function processArray that accepts an integer array, its size, and a callback function as arguments.
Implement callback functions (increment, doubleValue) that modify array elements in different ways.
Demonstrate invoking processArray with different callback functions.
*/
#include<stdio.h>
void increment(int *arr,int size){
    for(int i=0;i<size;i++) arr[i]++;
}
void doubleValue(int *arr,int size){
    for(int i=0;i<size;i++) arr[i]*=2;
}
void processArray(int *arr,int size,void (*func_ptr)(int*,int)){
    func_ptr(arr,size);
}
void print(int *p,int n){
    printf("Array: ");
    for(int i=0;i<n;i++) printf("%d ",p[i]);
    printf("\n");
}
int main(){
    int arr[5]={1,2,3,4,5};
    processArray(arr,5,increment);
    print(arr,5);
    processArray(arr,5,doubleValue);
    print(arr,5);
}