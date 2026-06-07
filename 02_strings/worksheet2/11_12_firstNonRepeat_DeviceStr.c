/*
11. Divide a string into N equal parts and print each part separately.
Input: "abcdefgh", N=4
Output: "ab", "cd", "ef", "gh"

12. Find the first non-repeating character in a string and print it.
Input: "swiss"
Output: 'w'
*/

#include<stdio.h>
#include<string.h>

/* first non-repeating character in a string */
void firstNonRepeat(char *str)
{
	int j;
	for(int i=0;str[i];i++)
	{
		for(j=i+1;str[j];j++)
			if(str[i]==str[j]) break;
		if(j==strlen(str)){
			printf("%c\n",str[i]);
			break;
		}
	}
}

/*divide string into equal parts */
void divide(char *str)
{
	int parts,len=strlen(str),prev;
	printf("Enter no.of parts required:");
	scanf("%d",&parts);
	if(parts<=0 || parts>len){
		printf("String division is not possible\n");
		return;
	}
	parts=len/parts;
	if((len%parts)==0){
		prev=0;
		for(int i=0;str[i];i++){
			if((i%parts)==0 && i!=0){
				prev=i;
				printf(",");
			}
			printf("%c",str[i]);
		}
	}
	else{
		printf("Eqaul parts division is not possible\n");
	}
}

int main(){
	char str[50];
	printf("Enter string:");
	scanf("%[^\n]s",str);
	firstNonRepeat(str);
	divide(str);
}
