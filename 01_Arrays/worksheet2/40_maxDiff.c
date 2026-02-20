/*
Find the maximum difference between two elements such that larger element appears after the smaller
 
Question description:
Write a C program to find the maximum difference between two elements in an array such that the larger element appears after the smaller element.
Sample data:
Input: 2 3 10 6 4 8 1
Expected output:
Maximum difference: 8 (10 - 2)*/

#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>

void maxDiff(int *arr,int n){
    if(n<2){
        printf("Array should contain at least two elements.\n");
        return;
    }
    int min_element=arr[0],current_diff;
    int max_diff=arr[1]-arr[0];
    for(int i=1;i<n;i++){
        current_diff=arr[i]-min_element;
        if(current_diff>max_diff)
            max_diff=current_diff;
        if(arr[i]<min_element)
            min_element=arr[i];
    }
    printf("Maximum difference: %d\n",max_diff);
    return;
}
void support_fun(int size){
    int arr[size];
    printf("Enter array elements:\n");
    for(int i=0;i<size;i++){
        scanf("%d",arr+i);
    }
    maxDiff(arr,size);
    return;
}
int main(){
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    if(size<=0){
        printf("Array with given size is not possible\n");
        return 0;
    }
    support_fun(size);
    return 0;
}