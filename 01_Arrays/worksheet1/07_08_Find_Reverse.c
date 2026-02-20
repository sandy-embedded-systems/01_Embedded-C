/*
7. Question: Find for an element
Question description: Write a C program to search for a number in an array and print its index.
Sample data:
Array: 10 20 30 40 50
Find: 30
Expected output:
Element found at index: 2

8. Question: Reverse an array
Question description: Write a C program to reverse an array in-place.
Sample data:
Input: 10 20 30 40 50
*/

#include<stdio.h>
void FindIdx(int *p,int size)
{
	int testData,i;
	printf("Enter Element to find:");
	scanf("%d",&testData);
	for(i=0;i<size;i++){
		if(p[i]==testData){
			printf("Elemet Found at index:%d\n\n\n",i);
			break;
		}
	}
	if(i==size) printf("No such element in array\n\n\n");
	return;
}
void Reverse(int *p,int n)
{
	for(int i=0,j=n-1;i<j;i++,j--){
		p[i]^=p[j]^=p[i]^=p[j];
	}
	printf("Reversed array:\n");
	for(int i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	return;
}

void Input(int size)
{
	int arr[size];
	printf("Enter elements:");
	for(int i=0;i<size;i++){
		scanf("%d",arr+i);
	}
	FindIdx(arr,size);
	Reverse(arr,size);
	return;
}
int main(){
	int n;
	printf("Enter size:");
	scanf("%d",&n);
	Input(n);
	return 0;
}
