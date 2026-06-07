/*
4.Write a program to check bit status in an integer:
Check if LSB is set (1) or not (0)
Check if MSB is set (1) or not (0)
Check if the nth bit is set (1) or not (0) (user input)

5.Write macros to set, clear, and toggle the nth bit using bitwise operators.

6.Write a C program to count the number of set bits in an unsigned integer.

7.How can you count the number of set bits in a floating-point number?
*/

#include<stdio.h>
/* Macros for the set,  clear, and toggle the nth bit */
#define SET(n,pos) (n|=1U<<pos)
#define CLEAR(n,pos) (n&=~(1U<<pos))
#define TOGGLE(n,pos) (n^=1U<<pos)

/* check status of a bit */
void checkStatusOfbit(int n)
{
	int pos;
	if(n&1) printf("LSB status is 1\n");
	else printf("LSB status is 0\n");
	if((n>>31)&1) printf("MSB status is 1\n");
	else printf("MSB status is 0\n");
	printf("Enter bit pos to check status:");
	scanf("%d",&pos);
	if(pos<0 || pos>=32){
		printf("bit Position is outof range\n");
		return;
	}
	if(n&(1<<pos)) printf("%d bit status is 1\n",pos);
	else printf("%d bit status is 0\n",pos);
}

/* set bit count in an integer */
void setBitCnt(int n)
{
	int cnt=0;
	for(int i=0;i<32;i++)
		if((n>>i)&1) cnt++;
	printf("No.of set bits:%d\n\n\n",cnt);
}

/* set bit count of a float number */
void setBitFloat(float n)
{
	int *p=(int*)&n,cnt=0;
	for(int i=0;i<32;i++){
		if(((*p)>>i)&1) cnt++;
	}
	printf("No.of set bits in float number:%d\n\n\n",cnt);
}
int main(){
	int n;
	float f;
	printf("Enter an integer:");
	scanf("%d",&n);
	printf("Enter float number:");
	scanf("%f",&f);
	setBitCnt(n);
	setBitFloat(f);
	checkStatusOfbit(n);
}
