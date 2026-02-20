/*
19. Question: Left rotate array by n
Question description: Write a C program to rotate an array to the left by n positions.
Sample data:
Array: 1 2 3 4 5
Rotate by: 2
Expected output:
Rotated array: 3 4 5 1 2

20. Question: Right rotate array by n
Question description: Write a C program to rotate an array to the right by n positions.
Sample data:
Array: 1 2 3 4 5
Rotate by: 2
Expected output:
Rotated array: 4 5 1 2 3
*/

#include<stdio.h>
#include<stdlib.h>

void print(int *p,int size){
	printf("The array:\n");
	for(int i=0;i<size;i++){
		printf("%d ",p[i]);
	}
}
/* Left Rotaion of an array by n positions*/
void RotateLeft(int *p,int size){
        int pos,temp;
        printf("Enter no.of positions to rotate left:");
        scanf("%d",&pos);
        if(pos<0){
                printf("ERROR: Roations is not possible\n");
                exit(0);
        }
	for(int i=0;i<pos;i++){
		temp=p[0];
		for(int j=0;j<size-1;j++)
			p[j]=p[j+1];
		p[size-1]=temp;
	}
	print(p,size);
}
/* Right Rotattion of an array by n positions*/
void RotateRight(int *p,int size){
	int pos,temp;
	printf("Enter no.of positions to rotate right:");
	scanf("%d",&pos);
	if(pos<0){
		printf("ERROR: Roations is not possible\n");
		exit(0);
	}
	for(int i=0;i<pos;i++){
		temp=p[size-1];
		for(int j=size-1;j>0;j--){
			p[j]=p[j-1];
		}
		p[0]=temp;
	}
	print(p,size);
}
void Task(int n){
        int arr[n];
        printf("Enter array elements:");
        for(int i=0;i<n;i++){
                scanf("%d",arr+i);
        }
	RotateRight(arr,n);
	RotateLeft(arr,n);
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

