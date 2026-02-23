/*
Use dynamic programming to check if a string is an interleaving of two other strings.
Input: s1 = "abc", s2 = "def", s3 = "adbcef"
Output: True
For a stream of characters, print the first non-repeating character at each step.
Input stream: "aabc"
Output: "a a b b"
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
/*  string is an interleaving of two other strings */
void inteleaving(char *s1,char *s2,char *s3){
    int l1=strlen(s1),l2=strlen(s2),l3=strlen(s3);
    if((l1+l2)!=l3){
        printf("False\n\n");
        return;
    }
    bool flag=1;
    for(int i=0,j=0;s3[i];i++,j++){
        if(s1[j]==s3[i] && j%2!=0) continue;
        else if(s2[j]==s3[i] && j%2==0) continue;
        else{
            flag=0;
            break;
        }
    }
    if(flag) printf("True\n\n");
    else printf("false\n\n");
    return;
}

/* first non-repeating character at each step. */
void firstNonRepeating(char *stream){
    int freq[256]={0};
    char queue[50],ch;
    int front=0,rear=0;
    for (int i=0;stream[i];i++){
        ch=stream[i];
        freq[ch]++;
        queue[rear++]=ch;
        while(front<rear && freq[queue[front]]>1)
            front++;
        if(front<rear)
            printf("%c ",queue[front]);
        else
            printf("-1 ");
    }
}
int main(){
    char s1[20],s2[20],s3[40];
    printf("Enter s1:");
    scanf("%s",s1);
    printf("Enter s2:");
    scanf("%s",s2);
    printf("Enter s3:");
    scanf("%s",s3);
    inteleaving(s1,s2,s3);
    firstNonRepeating(s1);
    return 0;
}