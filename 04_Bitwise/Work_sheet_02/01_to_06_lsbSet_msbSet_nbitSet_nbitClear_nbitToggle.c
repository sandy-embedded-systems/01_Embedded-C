/*
1. Check Least Significant Bit (LSB) of a number is set or not
Question: Write a C program to check if the Least Significant Bit (LSB) of a number is set (1) or not.
Sample data: Input: 5 (binary 0101)
Expected output: LSB of 5 is set (1)

2. Check Most Significant Bit (MSB) of a number is set or not
Question: Write a C program to check if the Most Significant Bit (MSB) of a number is set (1) or not.
Sample data: Input: 128 (binary 10000000 for 8-bit number)
Expected output: MSB of 128 is set (1)

3. Get nth bit of a number
Question: Write a C program to get the value of the nth bit of a number.
Sample data: Input number: 10 (binary 1010), bit position: 2
Expected output: Bit 2 of 10 is 1

4. Set nth bit of a number
Question: Write a C program to set (make 1) the nth bit of a number.
Sample data: Input number: 10 (binary 1010), bit position: 1
Expected output: Number after setting bit 1: 10 (binary 1010) — no change
Input number: 8 (binary 1000), bit position: 0
Expected output: Number after setting bit 0: 9 (binary 1001)

5. Clear nth bit of a number
Question: Write a C program to clear (make 0) the nth bit of a number.
Sample data: Input number: 10 (binary 1010), bit position: 3
Expected output: Number after clearing bit 3: 2 (binary 0010)

6. Toggle nth bit of a number
Question: Write a C program to toggle (flip) the nth bit of a number.
Sample data: Input number: 10 (binary 1010), bit position: 1
Expected output: Number after toggling bit 1: 8 (binary 1000)
*/

#include<stdio.h>
void Task(int n){
	int pos;
	/* check status of LSB */
	if(n&1) printf(" LSB of %d is set (1)\n\n",n);
	else printf(" LSB of %d is clear (0)\n\n",n);

	/* check status of MSB */
	if(n&(1U<<31)) printf("MSB of %d is set (1)\n\n",n);
	else printf("MSB of %d is clear (0)\n\n",n);

	/* nth bit of number */
	printf("Enter bit pos to find status:");
	scanf("%d",&pos);
	if(n&(1U<<pos)) printf("bit %d of %d is 1\n\n",pos,n);
	else printf("bit %d of %d is 0\n\n",pos,n);

	/* set nth of a number */
	printf("Enter bit pos to set:");
        scanf("%d",&pos);
	printf("Number after setting bit %d: %d\n\n",pos,(n|(1U<<pos)));

	/* clear nth bit of a number */
	printf("Enter bit pos to clear:");
        scanf("%d",&pos);
        printf("Number after clearing bit %d: %d\n\n",pos,(n&~(1U<<pos)));

	/* Toggle nth bit of anumber */
	printf("Enter bit pos to toggle:");
        scanf("%d",&pos);
        printf("Number after toggling bit %d: %d\n\n",pos,(n^(1U<<pos)));

}
int main(){
	int n;
	printf("Enter a number:");
	scanf("%d",&n);
	Task(n);
}
