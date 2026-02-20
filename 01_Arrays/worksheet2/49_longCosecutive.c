/*
49. Find longest consecutive sequence
 
Question description:
Write a C program to find the length of the longest consecutive elements sequence.
Sample data:
Input: 100 4 200 1 3 2
Expected output:
Longest consecutive sequence length: 4 (1, 2, 3, 4)
*/

#include<stdio.h>
void sort(int *p,int size){
        for(int i=0;i<size;i++){
                for(int j=i;j<size-1;j++){
                        if(p[j]>p[j+1]) p[j]^=p[j+1]^=p[j]^=p[j+1];
                }
        }
        return;
}
int lenConsecutiveSeq(int *arr,int size)
{
    	int longest=1,current=1;
    	sort(arr,size);
	for (int i=1;i<size;i++)
    	{
        	if(arr[i]==arr[i-1]+1)
       		{
            		current++;
       		}
        	else if(arr[i]!=arr[i-1]){
            		current=1;
		}
        	if(current>longest)
            		longest=current;
	}
    	return longest;
}
void Task(int n){
        int arr[n];
        printf("Enter array elements:");
        for(int i=0;i<n;i++){
                scanf("%d",arr+i);
        }
	printf("Longest consecutive sequence length:%d\n\n",lenConsecutiveSeq(arr,n));
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
