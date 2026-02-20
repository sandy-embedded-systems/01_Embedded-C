/*
5. Program: Reverse a string without using library functions
         Input: "OpenAI"

         Output: "IAnepO"

6. Program: Remove all extra blank spaces from a given string
         Input: " This is ChatGPT "

         Output: "This is ChatGPT"

7. Program: Replace all occurrences of a character with another in a string
         Input: "banana", replace 'a' with 'o'

 
         Output: "bonono"
*/

#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
/* Reveres string without using library function */
void reverse(char *s)
{
	for(int i=0,j=strlen(s)-1;i<j;i++,j--){
		s[i]^=s[j]^=s[i]^=s[j];
	}
	printf("Reversed string:\n%s\n\n",s);
	return;
}

/* Remove Extra spaces in the array */
void remExtraSpaces(char *s)
{
	int len=strlen(s),i,j;
	char *p=NULL;
	for(i=0;i<len;i++){
		if(s[i]==' ' && s[i]==' ')
		{
			for(j=i;j<len-1;j++)
				s[j]=s[j+1];
		}
	}
	printf("String After Removing Extra spaces:\n%s\n\n",s);
}

/* Replace all occurances of a char with another */
void replace(char *s)
{
	char old,new,ch,len=strlen(s);
	while((ch=getchar())!='\n');
	printf("which character do you want to replcace ? :");
	scanf("%c",&old);
	while((ch=getchar())!='\n');
	printf("with what character? :");
	scanf("%c",&new);
	for(int i=0;i<len;i++){
		if(s[i]==old) s[i]=new;
	}
}

int main(){
        char str[50];
        printf("Enter string:");
        scanf("%[^\n]s",str);
	reverse(str);
	remExtraSpaces(str);
	replace(str);
        printf("%s\n",str);
        return 0;
}
