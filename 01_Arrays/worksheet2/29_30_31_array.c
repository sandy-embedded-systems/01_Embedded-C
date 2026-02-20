/*
29. Check if array is palindrome
Question description:
Write a C program to check whether an array is palindrome (reads the same forward and backward).
Sample data:
Input: 1 2 3 2 1
Expected output:
The array is a palindrome.

30. Count pairs with given sum
Question description:
Write a C program to find number of pairs in the array whose sum is equal to a given value.
Sample data:
Input array: 1 5 7 -1 5 Sum = 6
Expected output:
Number of pairs: 3

31. Find missing number in array
Question description:
Write a C program to find the missing number in an array of size n containing numbers from 1 to n+1.
Sample data:
Input: 1 2 4 5 6
Expected output:
Missing number is: 3
*/

#include<stdio.h>
/* checking array is palindrome */
void isPalindrome(int *p,int size)
{
	char flag=0;
	for(int i=0,j=size-1;i<j;i++,j--){
		if(p[i]!=p[j]){
			flag=1;
			break;
		}
	}
	if(flag) printf("The array is not a palindrome\n\n");
	else printf("The array is a palindrome\n\n");
}
/* function to find no.of pairs whose sum=target */
void FindPairs(int *p,int n){
	int pairs=0,target;
	printf("Enter the target sum:");
	scanf("%d",&target);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((p[i]+p[j])==target) pairs++;
		}
	}
	printf("Total no.of Pairs:%d\n",pairs/2);
}

/* Missing number in the given array */
void MissingNumber(int *p,int n){
	int missing=0;
	for(int i=1;i<(n+1);i++){
		for(int j=0;j<n;j++){
			if(p[j]==i){
				break;
			}
			else missing=i;
		}
	}
	printf("Missing number:%d\n",missing);
}


void Task(int n){
        int arr[n];
        printf("Enter array elements:");
        for(int i=0;i<n;i++){
                scanf("%d",arr+i);
        }
	isPalindrome(arr,n);
	MissingNumber(arr,n);
	FindPairs(arr,n);
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
