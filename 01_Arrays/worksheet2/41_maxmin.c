/*
41. Find the minimum and maximum element using minimum comparisons
 
Question description:
Write a C program to find minimum and maximum elements using minimum number of comparisons.
Sample data:
Input: 1000 11 445 1 330 3000
Expected output:
Minimum element is 1 Maximum element is 3000
*/

#include<stdio.h>
#include<limits.h>
void minMax(int *p,int size){
	int min=INT_MAX,max=INT_MIN;
	for(int i=0;i<size;i++){
		if(p[i]<min) min=p[i];
		if(p[i]>max) max=p[i];
	}
	printf("Minimum element is %d Maximum element is %d\n",min,max);
}
void Task(int n){
        int arr[n];
        printf("Enter elements:\n");
        for(int i=0;i<n;i++){
                scanf("%d",arr+i);
        }
	minMax(arr,n);
        return;
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
