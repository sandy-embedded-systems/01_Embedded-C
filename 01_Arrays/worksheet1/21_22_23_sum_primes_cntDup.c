/*
21.Question: Sum of even numbers
Question description: Write a C program to find the sum of all even numbers in an array.
Sample data:
Input: 2 3 4 5 6
Expected output:
Sum of even numbers: 12
22. Question: Count prime numbers
Question description: Write a C program to count and display all prime numbers in an array.
Sample data:
Input: 2 4 5 6 7 8
Expected output:
Primes: 2 5 7
Count: 3
23. Question: Count duplicate elements
Question description: Write a C program to count how many duplicate values are in the array.
Sample data:
Input: 1 2 3 1 4 2
Expected output:
Total duplicate elements: 2
*/

#include<stdio.h>
/* function for sum of even numbers */
int sumOfEvens(int *p,int size){
	int sum=0;
	for(int i=0;i<size;i++){
		if(p[i]%2==0) sum+=p[i];
	}
	printf("\n\nSumof evens:%d\n\n",sum);
}

/* prime numbers in the array */
int isprime(int n){
	int i=2;
	if(n<=1) return 0;
	while(i<(n/2)){
		if(n%i==0) return 0;
	}
	return 1;
}
void countPrimes(int *p,int size){
	int cnt=0;
	printf("\n\nThe Primes:");
	for(int i=0;i<size;i++){
		if(isprime(p[i])){
			cnt++;
			printf("%d ",p[i]);
		}
	}
	printf("\nCount :%d\n\n",cnt);
}
/* counting duplicate elements in array */

void countDuplicates(int *p,int size)
{
	int flag=1,cnt=0;
        for(int i=0;i<size-1;i++){
                for(int j=i+1;j<size;j++){
                        if(p[i]==p[j]){
                                cnt++;
                                flag=0;
                        }
                }
        }
	if(flag) printf("\n\nNo duplicates in given array\n\n");
	else printf("\n\nTotal duplicates:%d\n\n",cnt);
	return;
}


void Task(int n){
        int arr[n];
        printf("Enter array elements:");
        for(int i=0;i<n;i++){
                scanf("%d",arr+i);
        }
	countPrimes(arr,n);
	countDuplicates(arr,n);
	sumOfEvens(arr,n);
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
