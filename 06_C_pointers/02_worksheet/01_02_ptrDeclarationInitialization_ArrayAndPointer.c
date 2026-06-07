/*
1. Pointer Declaration and Initialization
Goal: Declare pointers for various data types and initialize them properly to point to existing variables or dynamically allocated memory. Use pointer arithmetic and typecasting appropriately.

Activity:

Declare pointers to different data types (int, float, char).
Dynamically allocate memory for these pointers.
Assign addresses of variables to pointers and access their values through the pointers.
Perform pointer arithmetic to move through allocated memory blocks.
Use typecasting to convert pointers between compatible types.
 
2. Array and Pointer Arithmetic
Goal: Traverse and manipulate arrays by using pointers and pointer arithmetic instead of array indexing.

Activity:

Log Session an array of integers.
Use a pointer to iterate through the array elements by incrementing the pointer.
Perform operations like summing the elements or modifying them using only the pointer (no array indices).
Implement a function that receives a pointer and size to reverse the array elements in place.
*/

#include<stdio.h>
#include<stdlib.h>
void ptrExercise(void)
{
	int i=10;
	float f=3.4;
	char ch='A';
	int *ip=malloc(sizeof(int));
	float *fp=malloc(sizeof(float));
	char *cp=malloc(sizeof(char));
	ip=&i;
	fp=&f;
	cp=&ch;
	void *vp=ip;
	printf("%d ",*(int *)vp);
	vp=fp;
	printf("%.2f ",*(float *)vp);
	vp=cp;
	printf("%c\n\n",*(char *)vp);
}

/* Array and Pointer Arithmetic */
void reverse(int *arr,int n)
{
	for(int i=0,j=n-1;i<j;i++,j--)
		*(arr+i)^=(*(arr+j))^=(*(arr+i))^=(*(arr+j));
	printf("Reversed array: ");
	for(int i=0;i<n;i++)
		printf("%d ",*(arr+i));
	printf("\n\n");
}
void ptrArithmetic(void)
{
	int arr[]={10,20,30,40,50},sum=0;
	int *p=arr;
	for(int i=0;i<5;i++){
		sum+=(*p);
		p++;
	}
	printf("Sum=%d\n",sum);
	reverse(arr,5);
}

int main(){
	ptrExercise();
	ptrArithmetic();
}
