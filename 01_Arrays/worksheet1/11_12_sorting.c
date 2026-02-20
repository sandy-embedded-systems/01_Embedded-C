/*
11. Question: Sort array in ascending order
Question description: Write a C program to sort elements in ascending order.
Sample data:
Input: 20 5 10 8
Expected output:
Sorted array: 5 8 10 20

12. Question: Sort array in descending order
Question description: Write a C program to sort array elements in descending order.
Sample data:
Input: 7 2 9 4
Expected output:
Sorted array: 9 7 4 2
*/

#include<stdio.h>
void sortAscending(int *p,int size){
        for(int i=0;i<size;i++){
                for(int j=i;j<size-1;j++){
                        if(p[j]>p[j+1]){
                                p[j]^=p[j+1]^=p[j]^=p[j+1];
                        }
                }
        }
        return;
}
void sortDescending(int *p,int size){
        for(int i=0;i<size;i++){
                for(int j=i;j<size-1;j++){
                        if(p[j]<p[j+1]){
                                p[j]^=p[j+1]^=p[j]^=p[j+1];
                        }
                }
        }
        return;
}
void print(int *p,int size){
	for(int i=0;i<size;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}
void Input(int n){
	int arr[n],choice;
	printf("Enter elements:\n");
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	printf("1-for ascending sort\n2-descending sort\nSelect your choice:");
	scanf("%d",&choice);
	choice==1?sortAscending(arr,n):sortDescending(arr,n);
	print(arr,n);
	return;
}
int main(){
	int size;
	printf("Enter size:");
	scanf("%d",&size);
	Input(size);
}
