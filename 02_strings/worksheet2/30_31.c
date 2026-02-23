/*
Find the longest substring common to two given strings.
Input: "abcdxyz", "xyzabcd"
Output: "abcd"
Remove all occurrences of character 'b' and substring "ac" from a string.
Input: "abacb"
Output: "a"
*/

#include<stdio.h>
#include<string.h>

/* longest substring common in given two strings */
void longestCommonSubstring(char *s1,char *s2){
    int m=strlen(s1),n=strlen(s2),maxLen=0,start=0;
    int len;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            len=0;
            while(i+len<m && j+len<n &&s1[i+len]==s2[j+len])
                len++;
            if(len>maxLen){
                maxLen=len;
                start=i;
            }
        }
    }
    printf("Longest Common Substring: ");
    for(int i=0;i<maxLen;i++)
        printf("%c",s1[start+i]);
    printf("\n");
}

/* Remove all occurrences of character 'b' and substring "ac" from a string */
void remove_ch_str(char *str, char *dup, char ch)
{
    int i=0,j=0;
    int dup_len=strlen(dup);
    while(str[i]){
        if(str[i]==ch){
            i++;
        }
        else if(dup_len>0 && strncmp(&str[i],dup,dup_len)==0){
            i+=dup_len;
        }
        else{
            str[j++]=str[i++];
        }
    }
    str[j]='\0';
    printf("%s\n\n",str);
}
int main(){
    char s1[30],s2[30],ch;
    printf("Enter str1:");
    scanf("%s",s1);
    printf("Enter str2");
    scanf("%s",s2);
    longestCommonSubstring(s1,s2);
    memset(s1,'\0',30);
    memset(s2,'\0',30);
    printf("Enter main str:");
    scanf("%s",s1);
    printf("Enter str to remove:");
    scanf("%s",s2);
    printf("Enter character to remove:");
    scanf("%c",&ch);
    remove_ch_str(s1,s2,ch);
    return 0;
}