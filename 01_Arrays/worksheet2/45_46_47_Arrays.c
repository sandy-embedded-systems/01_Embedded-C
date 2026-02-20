/*
45. Move all zeros to end of array
Question description:
Write a C program to move all zeros in the array to the end while maintaining the order of non-zero elements.
Sample data:
Input: 1 0 2 0 0 3 4
Expected output:
Output: 1 2 3 4 0 0 0

46. Find the frequency of each element
Question description:
Write a C program to find the frequency of each element in the array.
Sample data:
Input: 10 20 10 30 20 20 10 10
Expected output:
10: 4 20: 3 30: 1

47. Find maximum sum of k consecutive elements 
Question description:
Write a C program to find maximum sum of k consecutive elements in an array.
Sample data:
Input: 2 3 4 1 5 6 7 k = 3
Expected output:
Maximum sum of 3 consecutive elements: 18
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Move all zeros to the end */
void moveZerosToEnd(int *p,int size){
	for(int i=0;i<size;i++){
		if(p[i]==0){
			memmove(p+i,p+i+1,sizeof(int)*(size-i+1));
			p[size-1]=0;
		}
	}
	for(int i=0;i<size;i++){
		printf("%d ",p[i]);
	}
	printf("\n\n");
}

/* Frequency of each number */
int test(int *p,int num,int size){
	for(int i=0;i<size;i++){
		if(p[i]==num) return 1;
	}
	return 0;
}
void freqOfEachNum(int *p,int size){
	int *temp=NULL,k=0,cnt;
	temp=(int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++){
		if(test(temp,p[i],k)){
			continue;
		}
		else{
			cnt=0;
			for(int j=0;j<size;j++){
				if(p[i]==p[j]) cnt++;
			}
			printf("%d:%d  ",p[i],cnt);
			temp[k++]=p[i];
		}
	}
	printf("\n\n");
	free(temp);
}

void Task(int n){
        int arr[n];
        printf("Enter elements:\n");
        for(int i=0;i<n;i++){
                scanf("%d",arr+i);
        }
	moveZerosToEnd(arr,n);
	freqOfEachNum(arr,n);
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
