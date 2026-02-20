#include<stdio.h>
#include<string.h>
/* check for palindrome */
void isPalindrome(char *str)
{
	int flag=0;
	for(int i=0,j=strlen(str)-1;i<j;i++,j--){
		if(str[i]!=str[j]){
			flag=1;
			break;
		}
	}
	if(flag){
		printf("Not a palindrome\n");
	}
	else printf("Palindrome\n");
	return;
}

/* Most frequent character */
void mostFreqChar(char *str)
{
	char ch;
	int len=strlen(str),freq=0,cnt;
	for(int i=0;i<len;i++){
		cnt=0;
		for(int j=0;j<len;j++){
			if(str[i]==str[j]) cnt++;
		}
		if(cnt>freq){
			freq=cnt;
			ch=str[i];
		}
	}
	printf("%c\n",ch);
}

int main(){
	char str[50];
	printf("Enter string:");
	scanf("%[^\n]s",str);
	isPalindrome(str);
	mostFreqChar(str);
	return 0;
}
