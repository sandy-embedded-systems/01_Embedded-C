/*
42. Count occurrences of a number
Question description:
Write a C program to count how many times a specific number appears in an array.
Sample data:
Input array: 1 2 3 2 2 5 Number to count: 2
Expected output:
Number 2 occurs 3 times

43. Find two elements whose sum is closest to zero
Question description:
Write a C program to find two elements whose sum is closest to zero.
Sample data:
Input: 1 60 -10 70 -80 85
Expected output:
Pair whose sum is closest to zero: -80 85

44. Rearrange positive and negative numbers
Question description:
Write a C program to rearrange an array so that positive and negative numbers are placed alternatively.
Sample data:
Input: 1 2 3 -4 -1 4
Expected output:
Rearranged array: -4 1 -1 2 3 4
*/

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
/* count occurances */
void countOccurances(int *p,int size){
	int cnt=0,num;
	printf("Enter number to count:");
	scanf("%d",&num);
	for(int i=0;i<size;i++){
		if(p[i]==num) cnt++;
	}
	printf("Number %d occurs %d times\n\n",num,cnt);
	return;
}

/* sum of elements whos sum is colsest to 0 */
void sumCloseToZero(int *p,int size){
	int idx1,idx2,sum=INT_MAX;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if((p[i]+p[j])<sum){
				sum=p[i]+p[j];
				idx1=i,idx2=j;
			}
		}
	}
	printf("Pair whose sum is closest to zero:%d %d\n\n",p[idx1],p[idx2]);
	return;
}

/* Rearrange all positive and negative elements alternatively */
void rearrange(int *p,int size){
	int *pos=NULL,*neg=NULL,i,j,k,l=0,m=0;

	pos=(int*)malloc(size*sizeof(int));
	neg=(int*)malloc(size*sizeof(int));
	for (int i=0;i<size;i++){
        	if (p[i]>=0)
            		pos[l++]=p[i];
        	else
            		neg[m++]=p[i];
	}
        i=0,j=0,k=0;
        while (i<l && j<m){
        	p[k++]=neg[i++];
	        p[k++]=pos[j++];
	}
        while(i<m)
       		p[k++]=neg[i++];
	while(j<l)
        	p[k++]=pos[j++];
   	free(pos);
    	free(neg);
    	printf("Array after Re-Arranging: ");
    	for(int i=0;i<size;i++){
		printf("%d ",p[i]);
	}
	printf("\n\n");
}
void Task(int n){
        int arr[n];
        printf("Enter elements:\n");
        for(int i=0;i<n;i++){
                scanf("%d",arr+i);
        }
	countOccurances(arr,n);
	sumCloseToZero(arr,n);
	rearrange(arr,n);
        return;
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



