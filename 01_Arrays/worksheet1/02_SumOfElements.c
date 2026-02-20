/*
Question: Sum of all elements in array
Question description: Write a C program to find the sum of all array elements entered by the user.
Sample data:
Input: 1 2 3 4 5
Expected output:
Sum = 15
*/

#include<stdio.h>

void SumOfElements(int *p,int size){
	int sum=0;
	for(int i=0;i<size;i++){
		sum+=p[i];
	}
	printf("Sum of Elements =%d\n",sum);
	return;
}

void Take_Input(int n){
        int arr[n];
        printf("Enter the elements:\n");
        for(int i=0;i<n;i++){
                scanf("%d",&arr[i]);
        }
        SumOfElements(arr,n);
}
int main(){
	int n;
	printf("Enter Size:");
	scanf("%d",&n);
	Take_Input(n);
	return 0;
}
