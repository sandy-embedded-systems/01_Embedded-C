/*
1. Program: Reverse order of words in a given string
          Input: "hello world from C"

 
         Output: "C from world hello"
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverseWords(char *s)
{
	int len=strlen(s);
	char *p[20],idx=0,*ptr=NULL,temp[len];
	for(ptr=s;ptr=strtok(ptr," ");){
		p[idx]=ptr;
		idx++;
		ptr=NULL;
	}
	memset(temp,'\0',len);
	strcpy(temp,p[idx-1]);
	for(int i=idx-2;i>=0;i--){
		strcat(temp," ");
		strcat(temp,p[i]);
	}
	strcpy(s,temp);
	printf("%s\n",s);
}

int main(){
	char str[50];
	printf("Enter string:");
	scanf("%[^\n]s",str);
	reverseWords(str);
//	printf("%s\n",str);
	return 0;
}
