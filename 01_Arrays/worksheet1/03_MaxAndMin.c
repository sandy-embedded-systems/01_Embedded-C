/*
Question: Find maximum and minimum element
Question description: Write a C program to find the largest and smallest element in the array.
Sample data:
Input: 8 3 15 6 2
Expected output:
Maximum = 15
Minimum = 2
*/

#include<stdio.h>
void FindMinMax(int *p,int n)
{
	int min=p[0],max=p[0];
	for(int i=0;i<n;i++){
		if(p[i]<min) min=p[i];
		if(p[i]>max) max=p[i];
	}
	printf("Min=%d\nMax=%d\n",min,max);
	return;
}
void Input(int n){
	int arr[n];
	printf("Enter elements:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	FindMinMax(arr,n);
	return;
}
int main(){
	int n;
	printf("Enter size:");
	scanf("%d",&n);
	Input(n);
	return 0;
}
