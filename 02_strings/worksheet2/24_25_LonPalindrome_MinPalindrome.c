/*
24. Partition a string into the minimum number of palindromic substrings (Palindrome Partitioning).
Input: "ababbbabbababa"
Output: 3

25. Find the longest palindromic substring inside a given string.
Input: "babad"
Output: "bab" or "aba"
*/

#include <stdio.h>
#include <string.h>

/* Find the longest palindromic substring inside a given string.*/
void longestPalindrome(char *s){
    int n=strlen(s);
    int start=0,maxLen=1;
    for(int i=0;i<n;i++){
        int l=i,r=i;
        while(l>=0 &&r<n&& s[l]==s[r]){
            if(r-l+1>maxLen){
                start=l;
                maxLen=r-l+1;
            }
            l--;
            r++;
        }
        l=i;
        r=i+1;
        while(l>=0 &&r<n&& s[l]==s[r]){
            if(r-l+1>maxLen){
                start=l;
                maxLen=r-l+1;
            }
            l--;
            r++;
        }
    }
    printf("Longest Palindrome: ");
    for(int i=start;i<start+maxLen;i++)
        printf("%c",s[i]);
    printf("\n");
}

/* Partition a string into the minimum number of palindromic substrings */
int min(int a, int b) {
    return (a < b) ? a : b;
}
int minPalPartition(char *s){
    int n=strlen(s);
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i]=i;
    for(int center=0;center<n;center++){
        int l=center;
        int r=center;
        while(l>=0 &&r<n &&s[l]==s[r]){
            if(l==0)
                dp[r]=0;
            else
                dp[r]=min(dp[r],dp[l-1]+1);
            l--;
            r++;
        }
        l=center;
        r=center+1;
        while(l>=0 &&r<n &&s[l]==s[r]){
            if(l==0)
                dp[r]=0;
            else
                dp[r]=min(dp[r],dp[l-1]+1);
            l--;
            r++;
        }
    }
    return dp[n-1];
}
int main() {
    char s[30];
    printf("Enter string:");
    scanf("%s",s);
    longestPalindrome(s);
    printf("min palindrome partitions:%d\n",minPalPartition(s));
    return 0;
}

