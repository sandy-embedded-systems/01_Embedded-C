/*
28. Match a string against a pattern containing wildcards '*' (any sequence) and '?' (single character).
Input: Pattern = "g*ks", String = "geeks"
Output: Match

29. Convert a numeric string to an integer without using built-in functions.
Input: "1234"
Output: 1234
*/

#include<stdio.h>
#include<string.h>
/* Match a string against a pattern containing wildcards '*' */
int wildcardMatch(char *pattern,char *str){
    if(*pattern=='\0' && *str=='\0')
        return 1;
    if(*pattern=='*'){
        while(*(pattern+1)=='*')
            pattern++;
        return wildcardMatch(pattern+1,str) ||(*str && wildcardMatch(pattern,str+1));
    }
    if(*pattern=='?'||*pattern==*str)
        return *str&& wildcardMatch(pattern+1,str+1);
    return 0;
}

/* Convert a numeric string to an integer */
int stringToInt(char *str){
    int result=0;
    int i=0;
    int sign=1;
    if(str[0]=='-'){
        sign=-1;
        i++;
    }
    while(str[i]){
        if(str[i]<'0'|| str[i]>'9')
            return 0;
        result=result*10+(str[i]-'0');
        i++;
    }
    return sign*result;
}
int main(){
    char pattern[30],str[30];
    printf("Enter pattern:");
    scanf("%s",pattern);
    printf("Enter string:");
    scanf("%s",str);
    wildcardMatch(pattern,str);
    memset(str,'\0',30);
    printf("enter number as string:");
    scanf("%s",str);
    printf("%d\n",stringToInt(str));
    return 0;
}