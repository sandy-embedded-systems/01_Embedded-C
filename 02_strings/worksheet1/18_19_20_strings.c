/*
18. Program: Trim both leading and trailing white space characters from given string
        Input: " Hello World "

        Output: "Hello World"

19. Program: Find first occurrence of a character in a given string
       Input: "elephant", find 'e'

        Output: Position: 0

20. Program: Find all occurrences of a word in given string
        Input: "the sky is the limit in the sky", search "the"

       Output: Found at positions: 0, 15, 30
       */
#include<stdio.h>
#include<string.h>

/* first occurrence of a character in a given string */
void firstOccurance(char *str)
{
	char ch,*p=NULL;
	while((ch=getchar())!='\n');
	printf("Enter character:");
	scanf("%c",&ch);
	p=strchr(str,ch);
	if(p){
		printf("Position :%ld\n",p-str);
	}
	else{
		printf("No such character in string\n");
	}
}

/*  Find all occurrences of a word in given string */
void allOccuranceOfWord(char *str){
	char word[20],*p=NULL;
	printf("Enter word to count:");
	scanf("%s",word);
	printf(" Found at positions:");
	for(p=str;p=strstr(p,word);p++){
		printf("%ld ",p-str);
	}
}

/* Trim both leading and trailing white space */
void trimSpaces(char *str)
{
	int i=0,len=strlen(str);
	while(str[i]==' '){
		for(int j=i;j<(len-1);j++)
			str[j]=str[j+1];
		i++;
	}
	i=strlen(str)-1;
	while(str[i]==' '){
		str[i]='\0';
		i--;
	}
	printf("%s\n\n",str);
}

int main(){
        char str[50];
        printf("Enter string:");
        scanf("%[^\n]s",str);
	firstOccurance(str);
//	allOccuranceOfWord(str);
//	trimSpaces(str);
        return 0;
}
