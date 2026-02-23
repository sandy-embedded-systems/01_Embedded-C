/*
Recursively remove all adjacent duplicate characters from a string until no duplicates remain.
Input: "azxxzy"
Output: "ay"
Rearrange characters in a string so that the same characters are at least d distance apart.
Input: "aabbcc", d=2
Output: "abcabc"
*/

#include<stdio.h>
#include<string.h>
#define MAX 100

int rearrange(char *str,int d) {
    int len=strlen(str);
    int freq[26]={0};
    int max,charIndex,pos;
    char result[MAX];
    for(int i=0;i<len;i++)
        result[i]='#';
    for(int i=0;i<len;i++)
        freq[str[i]-'a']++;
    while(1){
        max=0;
        charIndex=-1;
        for(int i=0;i<26;i++){
            if(freq[i]>max){
                max=freq[i];
                charIndex=i;
            }
        }
        if(max==0)
            break;
        pos=-1;
        for(int i=0;i<len;i++){
            if(result[i]=='#'){
                pos=i;
                break;
            }
        }
        if(pos==-1)
            return 0;
        while(pos<len &&freq[charIndex]>0){
            if(result[pos]=='#') {
                result[pos]=charIndex+'a';
                freq[charIndex]--;
                pos+=d;
            }
            else{
                pos++;
            }
        }
        if(freq[charIndex]>0)
            return 0;
    }
    result[len]='\0';
    strcpy(str,result);
    return 1;
}

/* Function to remove adjacent duplicates once */
int removeOnce(char *str){
    int i=0,j=0;
    int len=strlen(str),removed=0;
    while(i<len){
        if(i<len-1 &&str[i]==str[i+1]){
            removed=1;
            char ch=str[i];
            while(i<len && str[i]==ch)
                i++;
        }
        else {
            str[j++]=str[i++];
        }
    }
    str[j]='\0';
    return removed;
}
/* Recursive function */
void removeDuplicates(char *str){
    if (!removeOnce(str))
        return;      
    removeDuplicates(str);
}

int main() {
    char str[100];
    int dist;
    printf("Enter string to remove duplicates:");
    removeDuplicates(str);
    printf("Result: %s\n\n", str);
    memset(str,'\0',100);
    printf("Enter string to rearrange:");
    scanf("%s",str);
    printf("enter distance:");
    scanf("%d",&dist);
    rearrange(str,dist);
    printf("%s\n",str);
    return 0;
}