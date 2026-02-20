/*
15.Write a program to multiply a number by 9 using bitwise shift operations.

16.Write a program to determine the size (in bits) of an integer using bit shifts.

17.Write a program to convert a Little Endian integer to its Big Endian equivalent.
*/

#include<stdio.h>
/* Little Endian integer to its Big Endian */
void littleToBig(int n){
	printf("Little endian equivalent:0x%x\n",n);
	n=((n&0x000000FF)<<24)|((n&0x0000FF00)<<8)|((n&0x00FF00000)>>24)|((n&0xFF00000)>>8);
	printf("Big endian equivalent:0x%x\n",n);
}

/* sizeof int using shift operations */
void findSizeOfint(void)
{
	unsigned int x=1,cnt=0;
	while(x!=0){
		x=x<<1;
		cnt++;
	}
	printf("Size if int (int bits):%d\n\n",cnt);
}

/* multiply a number by 9 using bitwise shift operations. */
void multiply9(int n)
{
	int result=(n<<3)+n;
	printf("result=%d\n\n",result);
}
int main(){
	int input;
	printf("Enter a number:");
	scanf("%d",&input);
	littleToBig(input);
	findSizeOfint();
	multiply9(input);
	return 0;
}
