/*
Question: Print elements of an array

Question description: Write a C program to read n elements into an array and display them.

Sample data:
Enter the number of elements: 5
Enter the elements: 10 20 30 40 50

Expected output:
Elements in array are: 10 20 30 40 50
*/


#include<stdio.h>
void Display(int *p,int n){
	printf("Out put:\n");
	for(int i=0;i<n;i++){
		printf("%d ",p[i]);
	}
}
void Take_Input_And_Display(int n){
	int arr[n];
	printf("Enter the elements:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	Display(arr,n);
}

int main(){
	int n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	Take_Input_And_Display(n);
	return 0;
}
