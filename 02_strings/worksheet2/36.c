/*
Find the character with the second highest frequency in a string.
Input: "aabababa"
Output: 'b'
*/


#include<stdio.h>
#include<limits.h>
void secHighFreq(char *str)
{
        int max=0,secmax=INT_MIN,secidx;
        unsigned char seen[256]={0};
        for(int i=0;str[i];i++){
                seen[(unsigned char)str[i]]++;
        }
        for(int i=0;i<256;i++){
                if(max>seen[i]){
                        max=seen[i];
                }
        }
        for(int i=0;i<256;i++){
                if(seen[i]>secmax && seen[i]<max){
                        secmax=seen[i];
                        secidx=i;
                }
        }
        printf("%c\n",(char)secidx);
}


int main(){
        char str[50];
        printf("Enter string:");
        scanf("%[^\n]",str);
        secHighFreq(str);
}