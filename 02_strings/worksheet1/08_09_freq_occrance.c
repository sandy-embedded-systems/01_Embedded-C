/*
8. Program: Count frequency of each character in a string
         Input: "success"

         Output:
          s = 3
         u = 1
         c = 2
         e = 1

9. Program: Find first occurrence of a word in a given string
         Input: "this is a test string", word: "test"

         Output: Found at position 11
	 */

#include<stdio.h>
#include<string.h>
/* count frequency of each character in a string */
int checkPresence(char *t,char ch)
{
	for(int i=0;i<strlen(t);i++){
		if(t[i]==ch) return 0;
	}
	return 1;
}
void countFreq(char *str)
{
	int len=strlen(str),idx=0,cnt;
	char temp[len];
	for(int i=0;i<len;i++){
		if(checkPresence(temp,str[i])){
			cnt=0;
			for(int j=0;j<len;j++){
				if(str[i]==str[j]) cnt++;
			}
			temp[idx++]=str[i];
			printf("%c = %d\n",str[i],cnt);
		}
	}
}

/* First occurance of word */
void firstOccurance(char *str)
{
	char word[20],*p=NULL;
	printf("Enter the word to search:");
	scanf("%s",word);
	p=strstr(str,word);
	if(p==NULL) printf("No such word in main string\n");
	else printf("Found at position: %ld\n",p-str);
}

int main(){
        char str[50];
        printf("Enter string:");
        scanf("%[^\n]s",str);
	countFreq(str);
 	firstOccurance(str);
 	return 0;
}
