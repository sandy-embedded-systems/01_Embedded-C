/*
13.cQuestion: Merge two arrays
Question description: Write a C program to merge two arrays into a third array.
Sample data:
Array 1: 1 2 3
Array 2: 4 5 6
Expected output:
Merged array: 1 2 3 4 5 6
*/


#include<stdio.h>
#include<stdlib.h>
#define SIZE1 5
#define SIZE2 5
void input(int *p,int n){
	printf("Enter elements:\n");
	for(int i=0;i<n;i++){
		scanf("%d",p+i);
	}
}
void print(int *p,int n){
	for(int i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}
int *merge(int *p,int *q){
	int size=SIZE1+SIZE2;
	int *result=malloc(size);
	if(result==NULL){
		perror("malloc");
		printf("Program Terminated Due to Insufficient Memory\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0,j=0;i<size;i++)
	{
		if(i<SIZE1) result[i]=p[i];
		else result[i]=q[j++];
	}
	return result;
}
int main(){
	int arr[SIZE1],brr[SIZE2],*crr=NULL;
	input(arr,SIZE1);
	input(brr,SIZE2);
	crr=merge(arr,brr);
	print(crr,SIZE1+SIZE2);
	return 0;
}

	
