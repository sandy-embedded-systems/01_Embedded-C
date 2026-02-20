/*
2. Program: Remove all repeated characters from a given string
         Input: "programming"
        Output: "progamin"
*/

#include<stdio.h>
#include<string.h>
void remDuplicates(char *s)
{
	int len=strlen(s);
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;){
			if(s[i]==s[j]){
				for(int k=j;k<len;k++)
                   			s[k]=s[k+1];
				len--;
			}
			else j++;
		}
	}
}
int main(){
        char str[50];
        printf("Enter string:");
        scanf("%[^\n]s",str);
        remDuplicates(str);
	printf("%s\n",str);
        return 0;
}
