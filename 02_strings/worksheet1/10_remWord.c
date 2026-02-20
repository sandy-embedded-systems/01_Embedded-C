/*
10. Program: Remove all occurrence of a word in given string
           Input: "hello world hello universe", remove: "hello"

          Output: "world universe"
	  */

#include<stdio.h>
#include<string.h>
void remWords(char *str)
{
	char word[20],*p=NULL;
	int len,wordlen;
	printf("Enter word to remove:");
	scanf("%s",word);
	len=strlen(str);
	wordlen=strlen(word);
	for(p=str;p=strstr(p,word);){
		p--;
		for(int j=0;j<wordlen;j++){
			p[j]=p[j+wordlen+1];
		}
	}
	printf("%s\n",str);
}
int main(){
        char str[50];
        printf("Enter string:");
        scanf("%[^\n]s",str);
	remWords(str);
//        printf("%s\n",str);
        return 0;
}
