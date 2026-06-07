/*
11.Implement the function setbits(x, p, n, y) that sets n bits in x starting at position p with the rightmost n bits of y.

12.Given two integers A and B, write a program to count the number of bits that need to be flipped to convert A into B.

13.Write a program to reverse all bits in an integer.

14.Write a program to reverse:
	Bits at odd positions
	Bits at even positions
*/

#include<stdio.h>
/* reverse bits at odd positions and even postions */
void reverseOddEvenPos(int n)
{
	// reverse odd bit positions 
	int left=1,right=31,result=n,bit1,bit2;
	while(left<right){
		bit1=(result>>left)&1;
		bit2=(result>>right)&1;
		if(bit1!=bit2){
			result^=1<<right;
			result^=1<<left;
		}
		left+=2;
		right-=2;
	}
	printf("number after odd bit postions reversed:%d\n",result);
	result=n;
	left=0,right=30;
	while(left<right){
		bit1=(result>>left)&1;
		bit2=(result>>right)&1;
		if(bit1!=bit2){
			result^=1<<right;
			result^=1<<left;
		}
		left+=2;
		right-=2;
	}
	printf("number after odd bit postions reversed:%d\n",result);
}
/* Implement the function setbits() */
void setbits(int x,int y)
{
	int p,n;
	printf("Enter position to start:");
	scanf("%d",&p);
	printf("Enter no.of bits to be set:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		x=(x&~(1U<<p))|((y&(1U<<i))<<p);
		p++;
	}
	printf("x=%d y=%d\n\n",x,y);
}

/* count the number of bits that need to be flipped to convert A into B */
void flipBits(int a,int b)
{
	int temp=a^b,cnt=0;
	for(int i=0;i<32;i++){
		if(temp&(1U<<i)) cnt++;
	}
	printf("%d bits has to flip\n\n",cnt);
}

/* reverse all bits in an integer */
void reverseBits(int n)
{
	int status;
	for(int i=0;i<32;i++){
		status=n&1;
		n=n>>1;
		n|=status<<i;;
	}
	printf("number after bits are reversed:%d\n\n",n);
}
int main(){
	int x,y;
	printf("Enter x:");
	scanf("%d",&x);
	printf("Enter y:");
	scanf("%d",&y);
	setbits(x,y);
	flipBits(x,y);
	reverseBits(x);
	reverseOddEvenPos(x);
	return 0;
}
