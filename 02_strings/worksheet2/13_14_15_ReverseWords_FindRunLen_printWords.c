/*
13. Given a list of strings and a word, print the strings containing all characters of that word.
Input: Word = "act", List = ["cat", "tac", "act", "dog"]
Output: "cat", "tac", "act"

14.Reverse the order of words in a sentence without reversing the words themselves.
Input: "Hello world"
Output: "world Hello"

15.Compress a string using run-length encoding by replacing repeated characters with the character and count.
Input: "aaabbcc"
Output: "a3b2c2"
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define WORDS 4

/* reverse order of words */
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

/* run-length encoding by replacing repeated characters with the character and count */
void findRunLength(char *str)
{
	int cnt;
	for(int i=0;str[i];i++){
		if(str[i]==32) continue;
		cnt=0;
		for(int j=0;str[j];j++){
			if(str[i]==str[j]) cnt++;
		}
		printf("%c%d",str[i],cnt);
	}
	printf("\n\n");
}

/* print the strings containing all characters of that word */
void printWords(char *word)
{
	char *p[WORDS],*ptr=NULL;
	int len=strlen(word),i,j;
	printf("Enter list:\n");
	for(i=0;i<WORDS;i++){
		p[i]=calloc(1,30);
		printf("word%d:",i);
		scanf("%s",p[i]);
	}
	for(i=0;i<WORDS;i++){
		for(j=0;word[j];j++){
			if(strchr(p[i],word[j])) continue;
			else break;
		}
		if(j==len) printf("%s ",p[i]);
	}
}
int main(){
        char str[50];
        printf("Enter string:");
        scanf("%[^\n]s",str);
	printWords(str);
	findRunLength(str);
	reverseWords(str);
}
