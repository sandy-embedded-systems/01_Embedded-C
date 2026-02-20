
/*
 26. Find the union of two arrays
Question description:
Write a C program to find the union of two arrays (all unique elements from both arrays).
Sample data:
Array 1: 1 2 3 4 Array 2: 3 4 5 6
Expected output:
Union: 1 2 3 4 5 6
27. Find the intersection of two arrays
 
Question description:
Write a C program to find the intersection of two arrays (common elements).
Sample data:
Array 1: 1 2 3 4 Array 2: 3 4 5 6
Expected output:
Intersection: 3 4
*/

#include<stdio.h>
#include<string.h>

int exists(int arr[],int size,int key)
{
    	for(int i=0;i<size;i++)
        	if (arr[i]==key)
            		return 1;
   	return 0;
}
/* Union of Two arrays */
void FindUnion(int *a,int num1,int *b,int num2)
{
	int uni[num1+num2];
	int u=0;
    	for (int i=0;i<num1;i++)
   	 {
        	if(!exists(uni,u,a[i]))
            		uni[u++]=a[i];
	 }
    	for(int i=0;i<num2;i++)
    	{
        	if (!exists(uni,u,b[i]))
            		uni[u++]=b[i];
    	}
	printf("Union: ");
	for(int i=0;i<u;i++){
		printf("%d ",uni[i]);
	}
	printf("\n\n");
}
/* intersection of two arrays */
void FindIntersection(int *a,int num1,int *b,int num2)
{
	int in=0,inter[num1+num2];
	for(int i=0;i<num1;i++)
    	{
       		if(exists(b,num2,a[i]) && !exists(inter,in,a[i]))
            		inter[in++]=a[i];
    	}
	printf("intersection: ");
        for(int i=0;i<in;i++){
                printf("%d ",inter[i]);
        }
        printf("\n\n");
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
	printf("1.Find Union \n2.Find intersection\nYour choice:");
	scanf("%d",&choice);
	if(choice==1) FindUnion(arr,n,brr,m);
	else if(choice==2) FindIntersection(arr,n,brr,m);
	else printf("No such option available..\nexitting....\n\n");
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
