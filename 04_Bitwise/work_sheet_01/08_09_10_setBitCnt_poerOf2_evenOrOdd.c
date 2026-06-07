/*
Write a C program to count the number of bits set to 1 in an integer. Also compare different methods. Additionally, check if the 20th bit of a
32-bit integer is set.

9. Write a C program to check whether a number is a power of 2 using bitwise operations.

10.Write a C program to determine whether a number is odd or even using bitwise operators.
*/

#include<stdio.h>
void setBitCnt(int n)
{
	int cnt=0;
	printf("Method1:\ncheck each bit from lsb to msb and increment cnt if they are 1.\n");
	for(int i=0;i<32;i++)
		if(n&(1U<<i)) cnt++;// here we can also use condition: ((n>>i)&1U)
	printf("Method2:\ncheck each bit from  msb to lsb and increment cnt if they are 1.\n");
	cnt=0;
	for(int i=31;i>=0;i++)
		if((n>>i)&1U) cnt++;
	printf("no.of set bits:%d\n",cnt);
	if(n&(1U<<20)) printf("20th bit in %d is 1\n\n",n);
	else printf("20th bit in %d is 0\n\n",n);
}

/* check whether a number is a power of 2 */
void isPowerOf2(int n)
{
	if(n&(n-1)) printf("%d is a not power of 2\n\n",n);
	else printf("%d is power of 2\n\n",n);
}

/* a number is odd or even using bitwise operators */
void evenOrOdd(int n)
{
	if(n&1) printf("%d is an odd number\n\n",n);
	else printf("%d is an even number\n\n",n); 
}

int main(){
	int n;
	printf("enter a number:");
	scanf("%d",&n);
	evenOrOdd(n);
	isPowerOf2(n);
	setBitCnt(n);
}
