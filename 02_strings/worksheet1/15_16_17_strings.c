/*
15. Program: Count occurrences of a word in a given string
          Input: "hi hello hi hey hi", word: "hi"

         Output: 3

16. Program: Check whether a string is palindrome or not
        Input: "madam"

       Output: "Palindrome"

17. Program: Find last occurrence of a character in a string
        Input: "ababcabc", find 'b'

        Output: Position: 6
	*/

#include<stdio.h>
#include<string.h>
/* check for palindrome */
void checkPalindrome(char *s){
	int flag=0;
	for(int i=0,j=strlen(s)-1;i<j;i++,j--)
	{
		if(s[i]!=s[j]){
			flag=1;
			break;
		}
	}
	if(flag) printf("String is not a palindrome\n\n");
	else printf("String is a palindrome\n");
}

/* last occurance of char in given string */
void  lastOccurance(char *s)
{
	char *p=NULL,ch;
	while((ch=getchar())!='\n');
	printf("Enter character to find:");
	scanf("%c",&ch);
	p=strrchr(s,ch);
	if(p){
		printf("Position : %ld\n",p-s);
	}
	else{
		printf("No occurance found\n");
	}
}
/* Count occurrences of a word in a given string */
void countOccurances(char *s)
{
	char word[20],*p=NULL,ch;
	int cnt=0;
	while((ch=getchar())!='\n');
	printf("Enter word:");
	scanf("%s",word);
	for(p=s;p=strstr(p,word);p+=strlen(word)){
		cnt++;
	}
	printf("no.of occurances:%d\n\n",cnt);
}
int main(){
	char str[50];
	printf("Enter string:");
	scanf("%[^\n]s",str);
	countOccurances(str);
	checkPalindrome(str);
	lastOccurance(str);
}
