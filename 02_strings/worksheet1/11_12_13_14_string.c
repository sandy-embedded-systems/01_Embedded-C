/*
11. Program: Count total number of words in a string
          Input: "C programming is fun"

          Output: 4

12. Program: Toggle case of each character of a string
         Input: "HeLLo"

         Output: "hEllO"

13. Program: Remove last occurrence of a character from string
          Input: "mississippi", remove 's'

          Output: "missipippi"

14. Program: Replace first occurrence of a character with another in a string
         Input: "google", replace 'o' with 'a'

 
         Output: "gagole"
	 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

/* count words */
void countWord(char *str)
{
	int cnt=0,len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]==' ') cnt++;
	}
	printf("word count=%d\n\n",cnt);
}

/* toggle case of each char */
void toggleCase(char *str)
{
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(isalpha(str[i])) str[i]^=32;
	}
	printf("toggled string:\n%s\n\n",str);
}

/* Remove last occurance of a char */
void remLast(char *str)
{
	char ch,*p=NULL;
	int len=strlen(str);
	printf("Enter which character to remove:");
	while((ch=getchar())!='\n');
	scanf("%c",&ch);
	p=strrchr(str,ch);
	if(p){
		len=strlen(p);
		for(int i=0;i<len;i++){
			p[i]=p[i+1];
		}
		printf("last char removed:\n%s\n\n",str);
	}
	else printf("%s\n",str);
}

/* replace first occurance with another char */
void replaceFirst(char *str)
{
	char *p=NULL,ch,old,new;
	printf("which character you want to replcae:");
	while((ch=getchar())!='\n');
	scanf("%c",&old);
	while((ch=getchar())!='\n');
	printf("with what character:");
	scanf("%c",&new);
	p=strchr(str,old);
	if(p){
		*p=new;
		printf("%s\n",str);
	}
	else printf("Now such char in string\n");
}

int main(){
        char str[50];
        printf("Enter string:");
        scanf("%[^\n]s",str);
	replaceFirst(str);
	toggleCase(str);
	remLast(str);
	countWord(str);
        return 0;
}
