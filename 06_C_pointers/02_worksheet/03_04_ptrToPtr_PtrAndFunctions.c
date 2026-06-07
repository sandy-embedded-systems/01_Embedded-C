/*
3. Pointer to Pointer (Double Pointer)
Goal: Understand how to use double pointers for indirect referencing and dynamic memory management.

Activity:

Declare a double pointer and use it to dynamically allocate memory for a single variable or an array.
Access and modify the allocated memory via the double pointer.
Pass double pointers to functions to dynamically allocate or modify memory inside the function.
 
4. Pointer and Function
Goal: Use pointers to pass variables or arrays to functions so that the function can modify the original data.

Activity:

Write a function that takes pointers as parameters to swap two integer variables.
Log Session a function that modifies the elements of an array via a pointer.
Pass a pointer to a function to update the contents of a structure or a dynamically allocated memory block.
*/

#include<stdio.h>
#include<stdlib.h>
/* pointer to pointer */
void doublePtrs(int **ptr,int size)
{
	int *arr=malloc(sizeof(int)*size);
	printf("Enter array elements:\n");
	for(int i=0;i<size;i++)
		scanf("%d",arr+i);
	*ptr=arr;
}
void print(int **p,int size)
{
	for(int i=0;i<size;i++){
		printf("%d ",*(*p+i));
	}
	printf("\n\n");
}

/* pointer and function */
void swap(int *a,int *b)
{
	printf("Before swap :a=%d b=%d\n",*a,*b);
	*a^=*b^=*a^=*b;
	printf("After swap :a=%d b=%d\n\n",*a,*b);
}
void logFunc(int *p,int size)
{
	for(int i=0;i<size;i++)
		p[i]++;
	printf("Modified array:");
	for(int i=0;i<size;i++)
		printf("%d ",p[i]);
	printf("\n\n");
}

void main(){
	int *p=NULL,a=10,b=20;
	doublePtrs(&p,5);
	print(&p,5);
	logFunc(p,5);
	swap(&a,&b);
}
