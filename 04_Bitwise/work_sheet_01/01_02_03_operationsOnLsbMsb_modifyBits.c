/*
1. What are the functions of bitwise operators AND, OR, XOR, and shift operations?

2.Write a program to perform the following operations on the Least and Most Significant Bits (LSB/MSB) of a given integer:
Set the LSB to 1
Clear the LSB (set to 0)
Toggle the LSB
Set the MSB to 1
Clear the MSB (set to 0)
Toggle the MSB
Set a specific bit to 1
Clear a specific bit
Toggle a specific bit

3. Write a program to modify specific portions of a given integer:
Set all bits in the Least Significant Byte (LSB) to 1
Set all bits in the Most Significant Byte (MSB) to 1
Set all bits in the Least Significant Nibble to 1
Set all bits in the Most Significant Nibble to 1
Set n bits to 1 (user input)
Clear n bits (set to 0), with n as input
Toggle n bits (user input)
*/

#include<stdio.h>

/* perform the following operations on the MSB and LSB */
void opsOnMsbLsb(int n)
{
	int pos;
	printf("LSB set:%d\n",n|1); //sets LSB to 1
	printf("LSB clear:%d\n",n&(~1)); // clears LSB 
	printf("Toggle MSB:%d\n",n^(0x01));// Toggle LSB
	printf("MSB set:%d\n",n|(1U<<31)); //sets MSB 
	printf("MSB clear:%d\n",n&(~(1U<<31)));//Clear MSB
	printf("TOggle MSB:%d\n",n^(1U<<31)); // toggle MSB
	printf("Enter pos:");
	scanf("%d",&pos);
	printf("specific bit set to 1:%d\n",n|(1U<<pos)); // set a specific bit
	printf("specififc bit set to 0:%d\n",n&(~(1U<<pos)));// clear the specific bit
	printf("Specific bit toggle:%d\n\n\n",n^(1U<<pos)); //toggle the specific bit
}

/*  modify specific portions of a given integer */
void modify(int n)
{
	int input,temp;
	printf("lower byte set:%d\n",(n&~(0xFF))|(0xFF));
	printf("Higher byte set:%d\n",(n&~(0xFF<<24))|(0xFF<<24));
	printf("Lower nibble set:%d\n",(n&~(0xF))|(0xF));
	printf("Set all bits in the Most Significant Nibble:%d\n",(n&~(0xF<<28))|(0xF<<28));
	printf("\nEnter no.of bits to set:");
	scanf("%d",&input);
	if(input<0 || input>=32){
		printf("Invalid number choosed\n");
		return;
	}
	temp=n;
	for(int i=0;i<input;i++) temp|=1U<<i;
	printf("Set %d bits to 1: %d\n",input,temp);
	temp=n;
	for(int i=0;i<input;i++) temp&=~(1U<<i);
	printf("Clear %d bits to 0: %d\n",input,temp);
	temp=n;
	for(int i=0;i<input;i++) temp^=1U<<i;
	printf("toggle %d bits to 1: %d\n",input,temp);
}
int main(){
	int n;
	printf("Enter a number:");
	scanf("%d",&n);
	opsOnMsbLsb(n);
	modify(n);
}

