/*
 *
4. stion: Count even and odd elements
Question description: Write a C program to count how many even and odd numbers are in the array.
Sample data:
Input: 4 7 9 10 22
Expected output:
Even: 3
Odd: 2


5. stion: Copy array elements
Question description: Write a C program to copy all elements from one array to another.
Sample data:
Input: 1 2 3 4 5
Expected output:
Copied array: 1 2 3 4 5


6. stion: Count negative elements
Question description: Write a C program to count total number of negative elements in an array.
Sample data:
Input: -1 3 -4 5 0 -7
Expected output:
Total negative elements: 3
*/

#include<stdio.h>
void CountEvenOddEle(int*,int);
void CopyArray(int*,int);
int CountNegatives(int*,int);
void Tasks(int n){
	int arr[n],count;
	printf("Enter elements:");
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	CountEvenOddEle(arr,n);
	CopyArray(arr,n);
	count=CountNegatives(arr,n);
	printf("Total Negative elements: %d\n",count);
	return;
}

int main(){
	int n;
	printf("Enter size:");
	scanf("%d",&n);
	Tasks(n);
}
void CountEvenOddEle(int *p,int size){
	int evencnt=0,oddcnt=0;
	for(int i=0;i<size;i++){
		if(p[i]%2==0) evencnt++;
		else oddcnt++;
	}
	printf("Evens:%d\nOdds:%d\n",evencnt,oddcnt);
}
int CountNegatives(int *p,int n){
	int cnt=0;
	for(int i=0;i<n;i++){
		if(p[i]<0) cnt++;
	}
	return cnt;
}
void CopyArray(int *p,int n){
	int newArr[n];
	printf("Copied Array:\n");
	for(int i=0;i<n;i++){
		newArr[i]=p[i];
		printf("%d ",newArr[i]);
	}
	printf("\n");
	return;
}

