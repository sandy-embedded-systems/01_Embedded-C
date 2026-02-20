/*
11. Flip bits of a binary number using bitwise operator
Question: Write a C program to flip all bits of a number using bitwise operators.
Sample data: Input: 5 (binary 00000101)
Expected output: Flipped bits: 250 (binary 11111010) (assuming 8-bit)

12. Count total zeros and ones in a binary number
Question: Write a C program to count the total number of zeros and ones in the binary representation of a number.
Sample data: Input: 15 (binary 00001111)
Expected output: Number of ones: 4, Number of zeros: 4 (assuming 8-bit)

13. Rotate bits of a given number
Question: Write a C program to rotate bits of a number to the left or right by a given number of positions.
Sample data: Input: number=16 (binary 00010000), rotate left by 2
Expected output: Result after rotation: 64 (binary 01000000)

14. Convert decimal to binary using bitwise operator
Question: Write a C program to convert a decimal number to binary representation using bitwise operators.
Sample data: Input: 13
Expected output: Binary representation: 1101
*/

#include<stdio.h>
/* flip binary number using bitwise */
void flipBits(int n){
	printf("Flipped bits: %x\n\n",(n^0xFFFFFFFF));
	return;
}
/* count zeros and ones in a binary */
void countZerosOnes(int n){
	int ones=0,zeros=0;
	for(int i=0;i<32;i++){
		if(n&(1U<<i)) ones++;
		else zeros++;
	}
	printf("Number of ones: %d, Number of zeros: %d\n\n",ones,zeros);
}
/* rotate bits of given number */
void rotateLeft(int n){
	int rotations,fall;
	printf("Enter no.of rotations:");
	scanf("%d",&rotations);
	if(rotations>32) rotations-=32;
	fall=((n>>(32-rotations)) & ((1U<<rotations)-1));
	n=n<<rotations;
	n|=fall;
	printf("Result after rotation:%d\n\n",n);
}
/* decimal to binary conversion */
void decToBin(int n){
	printf("Binary representation:");
	for(int i=31;i>=0;i--)
		printf("%d",(n>>i)&1);
	printf("\n\n");
}
int main(){
	int input;
	printf("enter a number:");
	scanf("%d",&input);
	decToBin(input);
	rotateLeft(input);
	countZerosOnes(input);
	flipBits(input);
}
