/*
19. Find the length of the longest substring with no repeating characters.
Input: "abcabcbb"
Output: 3

20. Print all possible interleavings of two strings, preserving the relative order of characters in each string.
Input: str1 = "AB", str2 = "CD"
Output: "ABCD", "ACBD", "ACDB", "CABD", "CADB", "CDAB"
*/
#include<stdio.h>
#include<string.h>
/*length of the longest substring*/
int longestUniqueSubstring(char *str) {
    int lastIndex[256];
    int maxLen=0;
    int start=0;
    for (int i=0;i<256;i++)
        lastIndex[i]=-1;
    for (int end=0;str[end]!='\0';end++){
        if(lastIndex[str[end]]>=start){
            start=lastIndex[str[end]]+1;
        }
        lastIndex[str[end]]=end;
        int currentLen=end-start+1;
        if (currentLen>maxLen)
            maxLen=currentLen;
    }
    return maxLen;
}
/*all possible interleavings of two strings,*/
void interleave(char *str1, char *str2,char *result,int i,int j,int pos) {
    if (str1[i]=='\0' && str2[j]=='\0'){
        result[pos]='\0';
        printf("%s\n",result);
        return;
    }
    if(str1[i]!='\0') {
        result[pos]=str1[i];
        interleave(str1,str2,result,i+1,j,pos+1);
    }
    if(str2[j]!='\0'){
        result[pos]=str2[j];
        interleave(str1,str2,result,i,j+1,pos+1);
    }
}

int main(){
    char str[]="abcabcbb";
    char s1[]="AB",s2[]="CD";
    char result[10];
    interleave(s1,s2,result,0,0,0);
    printf("Length: %d\n",longestUniqueSubstring(str));
    return 0;
}