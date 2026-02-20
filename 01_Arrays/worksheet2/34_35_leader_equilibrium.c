/*
34. Find leader elements in array
Question description:
Write a C program to find all leader elements in the array (elements greater than all elements to their right).
Sample data:
Input: 16 17 4 3 5 2
Expected output:
Leader elements: 17 5 2
35. Find equilibrium index
 
Question description:
Write a C program to find the index where the sum of elements to the left is equal to the sum to the right.
Sample data:
Input: -7 1 5 2 -4 3 0
Expected output:
Equilibrium index is 3
*/

#include<stdio.h>

/* Leader of the array */
void Leader(int *p,int size){
	int flag;
	printf("Leaders of array: ");
	for(int i=0;i<size;i++){
		flag=1;
		for(int j=i+1;j<size;j++){
			if(p[i]>p[j]) continue;
			else{
				flag=0;
				break;
			}
		}
		if(flag) printf("%d ",p[i]);
	}
	printf("\n");
}

/* Equilibrum of the array */
void Equilibrium(int *p,int size){
	int leftsum=p[0],rightsum=0,flag=1;
	for(int i=1;i<size-1;i++){
		rightsum=0;
		for(int j=i+1;j<size;j++){
			rightsum+=p[j];
		}
		if(leftsum==rightsum){
			printf("Equilibrium index is %d\n",i);
			flag=0;
			break;
		}
		else leftsum+=p[i];
	}
	if(flag) printf("The array doesn't have any Equilibrium index\n");
}
void Task(int n){
        int arr[n];
        printf("Enter elements:\n");
        for(int i=0;i<n;i++){
                scanf("%d",arr+i);
        }
	Leader(arr,n);
	Equilibrium(arr,n);
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
