/*
24. Question: Split array into halves
Question description: Write a C program to split the array into two halves and print them separately.
Sample data:
Input: 1 2 3 4 5 6
Expected output:
First half: 1 2 3
Second half: 4 5 6

25. Question: Segregate even and odd
Question description: Write a C program to arrange all even numbers first and then all odd numbers.
Sample data:
Input: 1 2 3 4 5 6
Expected output:
Even numbers: 2 4 6
Odd numbers: 1 3 5
*/
#include<stdio.h>
#include<string.h>
/* Split array into two halves */
void splitArray(int *p,int size){
	int i;
	if(size%2!=0){
		printf("Odd no.of elements in Array..\nSplitting into two equal halves is not possible...\n");
		return;
	}
	printf("First half: ");
	for(i=0;i<size/2;i++){
		printf("%d ",p[i]);
	}
	printf("\nSecond half: ");
	for(;i<size;i++){
		printf("%d ",p[i]);
	}
	printf("\n\n");
}

/* segregate even and odd numbers in array */
void segregateArray(int *p,int n){
	int pos=0,temp;
	for(int i=0;i<n;i++){
		if(p[i]%2==0) pos++;
		else{
			temp=p[i];
			memmove(p+i,p+i+1,sizeof(int)*(n-i+1));
			p[n-1]=temp;
		}
	}
	printf("Result array: ");
	for(int i=0;i<n;i++) printf("%d ",p[i]);
	printf("\n\n");
	return;
}

void Task(int n){
        int arr[n];
        printf("Enter array elements:");
        for(int i=0;i<n;i++){
                scanf("%d",arr+i);
        }
	splitArray(arr,n);
	segregateArray(arr,n);
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
