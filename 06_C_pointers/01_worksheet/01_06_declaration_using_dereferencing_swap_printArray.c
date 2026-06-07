/*
1. Pointer Declaration and Initialization
Goal: Understand how to declare a pointer and store the address of a variable.

Activity:

Declare an integer variable: int a = 5;
Declare a pointer to int: int *ptr;
Assign the address of a to ptr: ptr = &a;
Print both a and *ptr using printf.
2. Using & (Address-of) Operator
Goal: Learn how to find and print the memory address of variables.

Activity:

Declare variables of different types: int x;, float y;, char z;
Print their memory addresses using &x, &y, and &z.
3. Using * (Dereference) Operator
Goal: Learn how to access or modify a variable's value using a pointer.

Activity:

Declare int a = 10;
Log Session int *p = &a;
Change the value at the pointer: *p = 20;
Print a and *p to verify both are 20.
4. Swapping Two Numbers Using Pointers
Goal: Understand how to pass variables by reference to functions using pointers.

Activity:

Write a swap function: void swap(int *a, int *b)
In main(), declare two integers and call swap(&x, &y);
Print values before and after swapping.
5. Pointer Arithmetic with Arrays
Goal: Learn how to access array elements using pointer arithmetic.

Activity:

Declare: int arr[5] = {10, 20, 30, 40, 50};
Use int *p = arr;
Use a loop to print all elements via *(p + i).
 
6. Array Index vs Pointer Arithmetic
Goal: Understand that arr[i] and *(arr + i) give the same result.

Activity:

Use both arr[i] and *(arr + i) to print array elements.
Confirm outputs are the same.
*/

#include<stdio.h>
/* Pointer Declaration and Initialization */
void ptrDecInit(void){
	int a=5,*ptr=&a;// pointer declaration and initialization
	printf("%d %d\n\n",a,*ptr);
}

/* Using & (Address-of) Operator */
void useOfAddrOf(void)
{
	int x;
	float y;
	char z;
	printf("%p\n%p\n%p\n\n",&x,&y,&z);
}

/* Using * (Dereference) Operator */
void useOfDerefernce(void)
{
	int a=10;
	int *p=&a;
	*p=20;
	printf("%d %d\n\n",a,*p);
}

/* Swapping Two Numbers Using Pointers */
void swap(int *a,int *b)
{
	printf("Before swap:a=%d b=%d\n",*a,*b);
	int temp=*a;
	*a=*b;
	*b=temp;
	printf("After swap:a=%d b=%d\n",*a,*b);
}
/* Pointer Arithmetic with Arrays */
void printarray(int *arr,int size)
{
	for(int i=0;i<size;i++)
		printf("%d ",*(arr+i));
	printf("\n\n");
}
/* Array Index vs Pointer Arithmetic */
void print(int *arr,int size)
{
	printf("array (indexing):");
	for(int i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\narray (pointer arithmetic):");
	for(int i=0;i<size;i++)
		printf("%d ",*(arr+i));
}
void task(int size)
{
	int a,b,arr[size];
	printf("Enter a:");
	scanf("%d",&a);
	printf("Enter b:");
	scanf("%d",&b);
	printf("Enter array elements:\n");
	for(int i=0;i<size;i++)
		scanf("%d",arr+i);
	ptrDecInit();
	useOfAddrOf();
	useOfDerefernce();
	swap(&a,&b);
	printarray(arr,size);
	print(arr,size);
}

int main(){
	int size;
	printf("Enter array size:");
	scanf("%d",&size);
	if(size<0) printf("ERROR: array with %d size is not possible\n",size);
	else task(size);
	return 0;
}

