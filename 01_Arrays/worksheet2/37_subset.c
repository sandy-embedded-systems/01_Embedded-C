/*
37. Check if array is subset of another
 
Question description:
Write a C program to check if one array is a subset of another array.
Sample data:
Array 1: 1 2 3 4 5 Array 2: 2 4 5
Expected output:
Array2 is a subset of Array1
*/

#include<stdio.h>
int isSubset(int *a,int n1,int *b,int n2)
{
	int j;
	if(n1<n2) return 0;
	for(int i=0;i<n2;i++){
		if(a[i]==b[0]){
			for(j=0;j<n2;j++,i++){
				if(a[i]!=b[j]) break;
			}
			if(j==n2) return 1;
		}
	}
	return 0;
}


void input(int *p,int size){
        printf("Enter array elements:");
        for(int i=0;i<size;i++){
                scanf("%d",p+i);
        }
        return;
}
void Task(int n,int m){
        int arr[n],brr[m],choice;
        input(arr,n);
        input(brr,m);
        if(isSubset(arr,n,brr,m)) printf("Array2 is a subset of Array1\n\n");
	else printf("Not a subset\n\n");
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
