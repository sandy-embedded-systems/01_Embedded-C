/*
7. Get highest set bit of a number
Question: Write a C program to find the position of the highest set bit in a number.
Sample data: Input: 18 (binary 10010)
Expected output: Highest set bit of 18 is at position 4 (zero-based)

8. Get lowest set bit of a number
Question: Write a C program to find the position of the lowest set bit in a number.
Sample data: Input: 18 (binary 10010)
Expected output: Lowest set bit of 18 is at position 1 (zero-based)

9. Count trailing zeros in a binary number
Question: Write a C program to count the number of trailing zeros in the binary representation of a number.
Sample data: Input: 40 (binary 101000)
Expected output: Number of trailing zeros: 3

10. Count leading zeros in a binary number
Question: Write a C program to count the number of leading zeros in the binary representation of a number (assuming 32-bit integer).
Sample data: Input: 16 (binary 00000000000000000000000000010000)
Expected output: Number of leading zeros: 27
*/

#include<stdio.h>
/* highest set bit position */
void highestSetBit(int n){
	int i,pos;
	if(n==0){
		printf("No set bit found \n\n");
		return;
	}
	for(i=0;i<32;i++){
		if(n&(1U<<i)) pos=i;
	}
	printf("Highest set bit of %d is at position %d\n\n",n,pos);
}

/* lowest set bit pos */
void lowestSetBit(int n){
        int i;
        if(n==0){
                printf("No set bit found \n\n");
                return;
        }
        for(i=0;i<32;i++){
                if(n&(1U<<i)) break;
        }
        printf("lowest set bit of %d is at position %d\n\n",n,i);
}

/* no.of trailing seros of a number */
void trailingZeros(int n){
	int i;
	for(i=0;i<32;i++){
		if(n&(1U<<i)) break;
	}
	printf("Number of trailing zeros:%d\n\n",i);
}

/* no.of leading zeros */
void leadingZeros(int n){
	int i,cnt=0;
	for(i=31;i>=0;i--){
		if(n&(1U<<i)) break;
		cnt++;
	}
	printf("Number of leading zeros:%d\n\n",cnt);
}

int main(){
	int input;
	printf("Enter a number:");
	scanf("%d",&input);
	highestSetBit(input);
	lowestSetBit(input);
	trailingZeros(input);
	leadingZeros(input);
	return 0;
}

