/*
21. Check if a string is an interleaving of two other strings, i.e., formed by merging them maintaining order.
Input: s1 = "abc", s2 = "def", s3 = "adbcef"
Output: True

22. Check if two strings are anagrams of each other by comparing character counts.
Input: "listen", "silent"
Output: True
*/
#include<stdio.h>
#include<string.h>
/* check if a string is an interleaving of two other strings */
void interLeaving(char *s1,char *s2,char *s3)
{
        int i=0,j=0,flag=1,l1=strlen(s1),l2=strlen(s2),l3=strlen(s3);
        if(l1!=l2 || (l1+l2)!=l3){
                printf("False\n\n");
                return;
        }
        for(i=0,j=0;s1[i];){
/*              if(s1[i]==s3[j++] && i%2==0) continue;
                else if(s2[i]==s3[j++] && i%2!=0) continue;
*/              if(s1[i]==s3[j] || s2[i]==s3[j]) j++;
                else{
                        i++;
                }
        }
        if(strlen(s3)!=j) printf("False\n\n");
        else printf("True\n\n");
      if(flag) printf("True\n\n");
}

/* check the given two strings are anagrams */
void anagram(char *s1,char *s2)
{
        unsigned char seen[255]={0};
        int i;
        if(strlen(s1)!=strlen(s2)){
                printf("Anagram:False\n\n");
                return;
        }
        for(i=0;s1[i];i++){
                seen[s1[i]]++;
                seen[s2[i]]--;
        }
        for(i=0;i<255;i++){
                if(seen[i]!=0) break;
        }
        if(i==255) printf("Anagram:True\n\n");
        else printf("Anagram:False\n\n");
}
int main(){
        char str1[20],str2[20],str3[50];
        printf("Enter string1:");
        scanf("%s",str1);
        printf("Enter string2:");
        scanf("%s",str2);
        printf("Enter string3:");
        scanf("%s",str3);
        interLeaving(str1,str2,str3);
        anagram(str1,str2);
}