/*
15. Question: Remove duplicate elements
Question description: Write a C program to remove duplicate elements from an array.
Sample data:
Input: 2 3 2 4 3 5
Expected output:
Array after removing duplicates: 2 3 4 5

16. Question: Find duplicate elements
Question description: Write a C program to find all duplicate elements in an array.
Sample data:
Input: 1 2 3 2 4 1
Expected output:
Duplicate elements: 1 2
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void print(int *p,int size)
{
	printf("The array: ");
	for(int i=0;i<size;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}
void RemAndDisp_Duplicates(int *p,int size)
{
	int flag=1,cnt=0;
	printf("Duplicates:");
	for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
			if(p[i]==p[j]){
				cnt++;
				printf("%d ",p[i]);
				memmove(p+j,p+j+1,sizeof(int)*(size-j+1));
				flag=0;
			}
		}
	}
	printf("\n");
	size-=cnt;
	if(flag){
		printf("No duplicates in the array...\n");
	}
	else print(p,size);
	return;
}

void TaskFunction(int size)
{
	int arr[size];
	printf("Array:  ");
	for(int i=0;i<size;i++){
	//	arr[i]=rand()%1000;
	//	printf("%d ",arr[i]);
		scanf("%d",arr+i);
	}
	printf("\n");
	RemAndDisp_Duplicates(arr,size);
	return;
}

int main(){
	int n;
	printf("Enter size:");
	scanf("%d",&n);
	if(n<=0){
		printf("ERROR: Invalid Size....\nNote: Array with %d is not possible.\n",n);
		exit(EXIT_FAILURE);
	}
	TaskFunction(n);
}

