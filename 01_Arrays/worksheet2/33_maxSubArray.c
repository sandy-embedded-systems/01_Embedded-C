/*
33. Find subarray with maximum sum (Kadane’s Algorithm)
Question description:
Write a C program to find the maximum sum of a contiguous subarray.
Sample data:
Input: -2 -3 4 -1 -2 1 5 -3
Expected output:
Maximum contiguous sum is 7
*/

#include<stdio.h>
#include<limits.h>
int maxSum(int *p,int size){
	int curr_sum=0,max_sum=INT_MIN;
	for(int i=0;i<size;i++){
		curr_sum=p[i];
		if(curr_sum>max_sum)
			max_sum=curr_sum;
		if(curr_sum<0)
			curr_sum=0;
	}
	return max_sum;
}
void Task(int n){
	int arr[n];
	printf("Enter elements:\n");
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	printf("Maximun contiguous sum:%d\n",maxSum(arr,n));
}
	
int main(){
        int n;
	printf("Enter size of array:");
	scanf("%d",&n);
	if(n<=0){
		printf("ERROR: Array with size %d is not possible .....\n",n);
		return 0;
	}
	Task(n);
        return 0;
}
