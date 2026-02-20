/*
48. Rotate array by k positions
 
Question description:
Write a C program to rotate the elements of an array by k positions to the right.
Sample data:
Input: 1 2 3 4 5 k = 2
Expected output:
Output: 4 5 1 2 3
*/

#include<stdio.h>
void print(int *p,int size){
        printf("The array:\n");
        for(int i=0;i<size;i++){
                printf("%d ",p[i]);
        }
}
void Rotate(int *p,int size,int k){
        int temp;
        for(int i=0;i<k;i++){
                temp=p[size-1];
                for(int j=size-1;j>0;j--){
                        p[j]=p[j-1];
                }
                p[0]=temp;
        }
        print(p,size);
}
void Task(int n){
        int arr[n],k;
        printf("Enter array elements:");
        for(int i=0;i<n;i++){
                scanf("%d",arr+i);
        }
	printf("Enter no.of times to rotate:");
	scanf("%d",&k);
	if(k<0){
		printf("rotations cannot be nagative\n\n");
		return;
	}
	Rotate(arr,n,k);
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
