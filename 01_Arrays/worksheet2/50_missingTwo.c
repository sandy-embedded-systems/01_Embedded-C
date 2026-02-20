/*
Find the missing two numbers in an array
Question description:
Write a C program to find two missing numbers from an array containing numbers from 1 to n+2.
Sample data:
Input: 1 2 4 6
Expected output:
Missing numbers: 3 5
*/
#include<stdio.h>
#include <stdio.h>

void missingTwo(int *arr,int n){
    int miss1,miss2,total_numbers=n+2;
    int total_sum=(total_numbers*(total_numbers+1))/2;
    int arr_sum=0,sum_missing,avg,sum_first_half;
    for(int i=0;i<n;i++)
        arr_sum += arr[i];
    sum_missing=total_sum-arr_sum;
    avg=sum_missing/2;
    sum_first_half=(avg*(avg+1))/2;
    int arr_first_half_sum = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<=avg)
            arr_first_half_sum+=arr[i];
    }
    miss1=sum_first_half-arr_first_half_sum;
    miss2=sum_missing-miss1;
    printf("Missing numbers: %d %d\n",miss1,miss2);
    return;
}
void support_fun(int size){
    int arr[size];
    printf("Enter array elements:\n");
    for(int i=0;i<size;i++){
        scanf("%d",arr+i);
    }
    missingTwo(arr,size);
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