/*
36. Find second smallest element
Question description:
Write a C program to find the second smallest element in the array.
Sample data:
Input: 12 13 1 10 34 1
Expected output:
Second smallest element is 10
*/


#include<stdio.h>
#include<limits.h>
int secSmall(int *p,int size)
{
	int min=p[0],secMin=INT_MAX;
	for(int i=0;i<size;i++){
		if(p[i]<min) min=p[i];
	}
	for(int i=0;i<size;i++){
		if(p[i]<secMin && p[i]>min) secMin=p[i];
	}
	return secMin;
}
void Task(int n){
        int arr[n];
        printf("Enter elements:\n");
        for(int i=0;i<n;i++){
                scanf("%d",arr+i);
        }
	printf("Second smallest elements:%d\n",secSmall(arr,n));
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
