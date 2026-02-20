/*
Find the smallest substring in a string containing all characters of another string.
Input: str1 = "this is a test string", str2 = "tist"
Output: "t stri"
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX_CHARS 256
void findSmallestWindow(char *str1, char *str2) {
    int len1=strlen(str1);
    int len2=strlen(str2);
    if(len1<len2){
        printf("No such window exists\n");
        return;
    }
    int hash_str1[MAX_CHARS]={0};
    int hash_str2[MAX_CHARS]={0};
    for(int i=0;i<len2;i++)
        hash_str2[str2[i]]++;
    int start=0,start_index=-1;
    int min_len=INT_MAX;
    int count=0;
    for(int end=0;end<len1;end++) {
        hash_str1[str1[end]]++;
        if (hash_str2[str1[end]]!=0 &&
            hash_str1[str1[end]]<=hash_str2[str1[end]]) {
            count++;
        }
        if(count==len2) {
            while(hash_str1[str1[start]] >hash_str2[str1[start]] ||hash_str2[str1[start]]==0){
                if (hash_str1[str1[start]] >hash_str2[str1[start]])
                    hash_str1[str1[start]]--;
                start++;
            }
            int window_len=end-start+1;
            if (window_len<min_len){
                min_len=window_len;
                start_index=start;
            }
        }
    }
    if(start_index==-1){
        printf("No such window exists\n");
        return;
    }
    printf("Smallest window: ");
    for(int i=start_index;i<start_index+min_len;i++)
        printf("%c", str1[i]);
    printf("\n");
}

int main() {
    char str1[]="this is a test string";
    char str2[]="tist";
    findSmallestWindow(str1, str2);
    return 0;
}