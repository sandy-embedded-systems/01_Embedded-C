/*
13. Question: Frequency of each element
Question description: Write a C program to count the frequency of each element in an array.
Sample data:
Input: 1 2 2 3 3 3
Expected output:
1 occurs 1 time
2 occurs 2 times
3 occurs 3 times
*/

#include<stdio.h>
void FindFrequency(int *p,int size){
	int cnt,flag;
	for(int i=0;i<size;i++){
		cnt=0,flag=0;
		for(int j=0;j<i;j++){
			if(p[i]==p[j]){
				flag=1;
				break;
			}
		}
		if(flag) continue;
		for(int j=0;j<size;j++){
			if(p[i]==p[j]) cnt++;
		}
		if(cnt) printf("%d occurs %d times\n",p[i],cnt);
	}
	return;
}
void input(int size){
	if(size<=0){
		printf("array with %d size is invalid\n...EXIT_FAILURE...\n",size);
		return;
	}
	int arr[size];
	printf("Enter array Elements:\n");
	for(int i=0;i<size;i++){
		scanf("%d",arr+i);
	}
	FindFrequency(arr,size);
	return;
}
int main(){
	int n;
	printf("Enter the size:");
	scanf("%d",&n);
	input(n);
}
