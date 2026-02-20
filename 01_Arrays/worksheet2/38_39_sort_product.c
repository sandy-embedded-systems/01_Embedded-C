/*
38. Sort array of 0s, 1s and 2s
Question description:
Write a C program to sort an array consisting of only 0s, 1s, and 2s.
Sample data:
Input: 0 1 2 0 1 2 1 0
Expected output:
Sorted array: 0 0 0 1 1 1 2 2

39. Find product of all elements 
Question description:
Write a C program to find the product of all elements in the array.
Sample data:
Input: 1 2 3 4
Expected output:
Product: 24
*/


#include<stdio.h>
/* sortint array havind 0's,1's,2's */
void sort(int *p,int size){
	for(int i=0;i<size;i++){
		for(int j=i;j<size-1;j++){
			if(p[j]>p[j+1]) p[j]^=p[j+1]^=p[j]^=p[j+1];
		}
	}
	printf("Array after sorting: ");
	for(int i=0;i<size;i++){
		printf("%d ",p[i]);
	}
	printf("\n\n");
	return;
}

/* peoduct of elements */
void product(int *p,int size)
{
	int prod=1;
	for(int i=0;i<size;i++){
		prod*=p[i];
	}
	printf("Product:%d \n",prod);
}

void Task(int n){
        int arr[n];
        printf("Enter elements:\n");
        for(int i=0;i<n;i++){
                scanf("%d",arr+i);
        }
	sort(arr,n);
	product(arr,n);
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

