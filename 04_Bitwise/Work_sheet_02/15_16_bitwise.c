/*
15. Swap two numbers using bitwise operator
Question: Write a C program to swap two numbers using bitwise XOR operator without using a temporary variable.
Sample data: Input: a=5, b=9
Expected output: After swapping: a=9, b=5

16. Check whether a number is even or odd using bitwise operator
Question: Write a C program to check whether a number is even or odd using bitwise AND operator.
Sample data: Input: 7
Expected output: 7 is odd
*/
#include<stdio.h>
/* even or odd using bitwise operator */
void evenOrOdd(int n){
	if(n&1) printf("Odd number\n\n");
	else printf("Even number\n\n");
}

/* swap two numbers using bitwise */
void swap(void){
	int a,b;
	printf("Enter a:");
	scanf("%d",&a);
	printf("Enter b:");
	scanf("%d",&b);
	a^=b^=a^=b;
	printf("After swapping: a=%d, b=%d\n\n",a,b);
}
int main(){
	int input;
	printf("Enter a number:");
	scanf("%d",&input);
	evenOrOdd(input);
	swap();
}
