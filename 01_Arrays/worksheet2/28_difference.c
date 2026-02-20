/*
28. Find the difference of two arrays
http://192.168.1.101/link/225#bkmrk-question-description-2
 
Write a C program to find the difference of two arrays (elements present in first array but not in second).
Sample data:
Array 1: 1 2 3 4 Array 2: 3 4 5 6
Expected output:
Difference (Array1 - Array2): 1 2
*/

#include<stdio.h>

void difference(int *a,int n1,int *b,int n2)
{
	int i,j;
	printf("Difference (Array1 - Array2):");
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			if(a[i]==b[j]) break;
		}
		if(j==n2) printf("%d ",a[i]);
	}
	printf("\n\n");
}
void input(int *p,int size){
        printf("Enter array elements:");
        for(int i=0;i<size;i++){
                scanf("%d",p+i);
        }
        return;
}
void Task(int n,int m){
        int arr[n],brr[m];
        input(arr,n);
        input(brr,m);
	difference(arr,n,brr,m);
       	return;
}
int main(){
        int n,m;
        printf("Enter array1 size:");
        scanf("%d",&n);
        printf("Enter array2 size:");
        scanf("%d",&m);
        if(n<=0 || m<=0){
                printf("ERROR: Arrays with sizes %d %d are not possible\n",n,m);
               return 0;
        }
        Task(n,m);
        return 0;
}
