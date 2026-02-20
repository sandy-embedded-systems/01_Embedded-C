/*
7. Modify Array Elements Using Pointers
Goal: Learn to modify values in an array using pointer operations.

Activity:

Log Session int arr[] = {2, 4, 6};
Use pointer arithmetic to increase each element by 1.
Print modified array.
8. NULL Pointer Safety
Goal: Learn to avoid dereferencing NULL pointers.

Activity:

Declare: int *p = NULL;
Use a condition if (p != NULL) before dereferencing.
Later, assign p = &a; and access safely.
9. Passing Array to Function
Goal: Learn how arrays are passed to functions as pointers.

Activity:

Write void display(int *arr, int n);
Inside the function, loop using pointer arithmetic to print elements.
10. Visualizing Memory Addresses
Goal: Visualize how memory is arranged for variables.

Activity:

Declare three local variables.
Print their addresses using printf.
Observe the increasing/decreasing pattern.
11. Pointer to Pointer (int **)
Goal: Learn how to use a pointer to another pointer.

Activity:

Declare int a = 5;, int *p = &a;, and int **pp = &p;
Print a, *p, and **pp to understand levels of indirection.
12. Garbage Pointer
Goal: Understand what happens when a pointer is used without initialization.

Activity:

Declare an uninitialized pointer int *p;
Try printing *p and observe the issue (garbage value or crash).
Then fix by assigning a valid address.
13. Pointer Type Compatibility
Goal: Understand the importance of matching pointer types.

Activity:

Declare int *ip; and float *fp;
Try assigning fp = ip; and observe compiler warning.
Correct the mismatch using proper types or casting.
*/

#include<stdio.h>
/* Modify Array Elements Using Pointers */
void modify(void){
	int arr[]={2,3,6};
	for(int i=0;i<3;i++)
		printf("%d ",++(*(arr+i)));
	printf("\n\n");
}
/* NULL pointer safety */
void checkNull(void)
{
	int *p=NULL,a=10;
	if(p!=NULL) printf("%d ",*p);
	p=&a;
	printf("%d ",*p);
}
/* passing array to function */
void display(int *arr,int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",*(arr+i));
	printf("\n\n");
}
/* Visualizing Memory Addresses */
void visualize(void)
{
	int a,b,c;
	printf("%p\n%p\n%p\n\n",&a,&b,&c);
}
/* Pointer to Pointer */
void doublePtr(void)
{
	int a=10,*p=NULL,**pp=NULL;
	p=&a;
	pp=&p;
	printf("%d %d %d\n\n",a,*p,**pp);
}
/* garbage pinter */
void garbagePtr(void){
	int x=10,*p;
	printf("Address in pointer:%p\n",p);
//	printf("%d \n",*p);//this line will result in segmentation fault
	p=&x;//its a valid address
	printf("%d %d\n\n",x,*p);
}
/* pointer Type compatibility */
void ptrType(void)
{
	int *ip;
	float *fp;
	ip=fp;
	//correct way ip=(int*)fp
}
int main(){
	int arr[]={10,20,30,40,50};
	modify();
	checkNull();
	display(arr,5);
	ptrType();
	garbagePtr();
	doublePtr();
	visualize();
}
