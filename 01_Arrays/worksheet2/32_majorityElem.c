/*
32. Find the majority element
 
Question description:
Write a C program to find the majority element in an array (element appearing more than n/2 times).
Sample data:
Input: 2 2 1 2 3 2 2
Expected output:
Majority element: 2

*/
#include<stdio.h>
int majorityNumber(int *p,int size){
	int cnt,major=p[0],prev_cnt=0;
	for(int i=0;i<size;i++){
		cnt=0;
		for(int j=0;j<size;j++){
			if(p[i]==p[j]) cnt++;
		}
		if(cnt>prev_cnt){
			prev_cnt=cnt;
			major=p[i];
		}
	}
	return major;
}
void Task(int n){
        int arr[n];
        printf("Enter elements:\n");
        for(int i=0;i<n;i++){
                scanf("%d",arr+i);
        }
        printf("Major element is:%d\n",majorityNumber(arr,n));
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
