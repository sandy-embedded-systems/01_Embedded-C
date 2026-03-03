
#include<stdio.h>
#include<stdarg.h>
#include<string.h>

/* sum of digits of each number*/
void sumOfDigits(int n,...){
    va_list args;
    va_start(args,n);
    int sum=0,num;
    for(int i=0;i<n;i++){
        num=va_arg(args,int);
        while (num)
        {
            sum+=num%10;
            num/=10;
        }
    }
    va_end(args);
    printf("Sum of digits of all numbers:%d\n",sum);
    return;
}


/* Count number of vowels present in the given strings */
int cnt_vowels(int n,...){
    char *vowels="aeiouAEIOU";
    char *p=NULL;
    va_list arguments;
    va_start(arguments,n);
    int cnt=0;
    for(int i=0;i<n;i++){
        p=va_arg(arguments,char*);
        for(int j=0;p[j];j++){
            if(strrchr(vowels,p[j])) cnt++;
        }
    }
    va_end(arguments);
    return cnt;
}
int main(){
    sumOfDigits(3,1234,5678,2234);
    printf("%d\n",cnt_vowels(2,"Hello","welcome"));
}
