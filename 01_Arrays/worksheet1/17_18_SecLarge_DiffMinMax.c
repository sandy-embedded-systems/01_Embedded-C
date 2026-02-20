/*
 17. Question: Find second largest element
Question description: Write a C program to find the second largest number in the array.
Sample data:
Input: 10 20 50 40
Expected output:
Second largest: 40

18. Question: Difference between max and min
Question description: Write a C program to find the difference between largest and smallest elements in an array.
Sample data:
Input: 5 1 9 3 6
Expected output:
Difference: 8
*/

#include<stdio.h>
/* Function to find difference between maximun and minimum*/
void FindDiffMinMax(int *p,int size){
	int min=p[0],max=p[0];
	for(int i=0;i<size;i++){
		if(p[i]>max){
			max=p[i];
			continue;
		}
		if(p[i]<min)
			min=p[i];
	}
	printf("Difference:%d\n",max-min);
}

/* Function to find Second Largest number:( question 17) */
void FindSecLarge(int *p,int size){
	int max=p[0],secMax=p[0];
	for(int i=0;i<size;i++){
		if(p[i]>max) max=p[i];
	}
	for(int i=0;i<size;i++){
		if(p[i]>secMax && p[i]<max) secMax=p[i];
	}
	printf("Second Maximun:%d\n",secMax);
}
		
void Task(int n){
	int arr[n];
	printf("Enter array elements:");
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	FindSecLarge(arr,n);
	FindDiffMinMax(arr,n);
	return;
}
int main(){
	int n;
	printf("Enter size:");
	scanf("%d",&n);
	if(n<=0){
		printf("ERROR: Array with size %d is not possible\n",n);
	       return 0;
	}
	Task(n);
	return 0;
}
