/*
Question 1: Pointer Increment and Access
Task: Log Session an integer array with 5 elements. Use a pointer to access and print the third element by incrementing the pointer appropriately.

Question 2: Pointer Addition
Task: Using the same array, print the last element by adding an integer to the pointer.

Question 3: Pointer Subtraction
Task: Given two pointers pointing to elements of an integer array, find the distance (number of elements) between them.

Question 4: Pointer Comparison
Task: Write code to compare two pointers to elements in an array and print which one points to the element with a smaller index.

Question 5: Traverse Array with Pointer Arithmetic
Task: Using only a pointer (no array indexing), print all elements of the array.

Question 6: Invalid Pointer Arithmetic
Task: Explain why the following code snippet is invalid and what would happen if you try to compile/run it:

Question 7: Pointer Arithmetic with Different Data Types
Task: Log Session a double array and use pointer arithmetic to print the second element. Explain how pointer arithmetic differs for double compared to int.

Question 8: Pointer Arithmetic and Array Bounds
Task: Write code that attempts to access memory outside an array using pointer arithmetic and explain why this is unsafe.

Question 9: Reverse Array using Pointer Arithmetic
Task: Write a function that reverses an integer array in place using pointer arithmetic only (no array indexing).

*/

#include<stdio.h>
/*  Pointer Increment and Access */
void print3rd(int *arr,int size)
{
	if(size<3){
		printf("No 3rd element\n\n");
		return;
	}
	printf("Third element is %d\n\n",*(arr+2));
}
/* Pointer Addtion */
void lastEle(int *st,int size)
{
	printf("Last element is %d\n\n",*(st+(size-1)));
}
/* pointer subtraction */
void distance(int *st,int *dst)
{
	printf("Distance between pointers is %ld\n\n",((dst-st)/sizeof(int)));
}
/* pointer comparision */
void ptrCompare(int *arr,int *p1,int *p2,int size)
{
	if((p1-arr)==(p2-arr)) printf("Pointer ptr1 and ptr2 points to same element\n\n");
	else if((p1-arr)<(p2-arr)) printf("Pointer ptr1 points to an earlier element than ptr2\n\n");
	else printf("Pointer ptr2 points to an earlier element than ptr1\n\n");
}
/* array printing without using indexing */
void print(int *arr,int size)
{
	for(int i=0;i<size;i++)
		printf("%d ",*(arr+i));
	printf("\n\n");
}
/*  Invalid Pointer Arithmetic */
void invalidOperation(void)
{
	int arr[5];
	int *p1 = &arr[1];
	int *p2 = &arr[3];
//	int *p3 = p1+p2; // Invalid operation
/*	printf("%d \n\n",*p3);  this line will result in Segmentation Fault : 
Reason: since pointers p1 and p2 are pointing to valid location , but addtion of these will result a pointer
that points to an unauthorised location , and the system will send a signal to this process thus terminating the process */
}
/* Pointer Arithmetic with Different Data Types */
void diffDataTypes()
{
	double arr[5]={1.23,5.67,3.33,6.77,8.09};
	printf("Second element is %f\n\n",*(arr+2));
	/* the difference between double * , and int * : in c , the pointer arithmetic is actually depends on sizeof data type
	 * ie., arr+1 is actually equals to arr+sizeof(double) 
	 * so, for adding 1 will increment arr by 8 bytes ,where as for int it is 4 bytes */
}
/* memory bounds check */
void checkBoundary(void)
{
	int ele,arr[]={10,20,30,40,50};
	printf("Enter an index:");
	scanf("%d",&ele);
	if(ele<0 || ele>5) printf("Undefined behavior - accessing memory outside the array may cause crash or unexpected results\n\n");
	else printf("Valid Index entered:\nvalue at %d is %d\n\n",ele,arr[ele]);
}
/* reverse array using pointer arithmetic */
void reverse(int *arr,int size)
{
	for(int i=0,j=size-1;i<j;i++,j--){
		(*(arr+i))^=(*(arr+j))^=(*(arr+i))^=(*(arr+j));
	}
	printf("reversed array: ");
	for(int i=0;i<size;i++){
		printf("%d ",*(arr+i));
	}
	printf("\n\n");
}
void Task(int size)
{
	int arr[size];
	printf("Enter elements:");
	for(int i=0;i<size;i++)
		scanf("%d",arr+i);
	print3rd(arr,size);
	distance(arr+1,arr+3);
	ptrCompare(arr,arr+1,arr+3,size);
	lastEle(arr,size);
	invalidOperation();
	print(arr,size);
	diffDataTypes();
	checkBoundary();
	reverse(arr,size);
}
void main(){
	int size;
	printf("Enter size of array:");
	scanf("%d",&size);
	if(size<0) printf("ERROR: array with %d size is not possible\n\n",size);
	else Task(size);
	return;
}
