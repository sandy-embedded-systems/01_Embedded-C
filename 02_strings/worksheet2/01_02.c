/*
1.Swap the contents of two strings without using any extra temporary string variables. The strings' values should be exchanged completely.
Input: str1 = "hello", str2 = "world"
Output: str1 = "world", str2 = "hello"

2.Sort an array of strings in alphabetical order. The sorted array should list strings from A to Z.
Input: {"John", "Alice", "Bob"}
Output: {"Alice", "Bob", "John"}*/

#include<stdio.h>
#include<string.h>
void swap(void){
    char str1[20]="hello";
    char str2[20]="world";
    int len1=strlen(str1);
    int len2=strlen(str2);
    int max=(len1>len2)? len1:len2;
    for(int i=0;i<=max;i++){   
        char temp=str1[i];
        str1[i]=str2[i];
        str2[i]=temp;
    }
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
}

void sortarrofstr(void){
    char arr[][20]={"John", "Alice", "Bob"};
    int n=3;
    char temp[20];
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(strcmp(arr[j],arr[j+1])>0){
                strcpy(temp,arr[j]);
                strcpy(arr[j],arr[j+1]);
                strcpy(arr[j+1],temp);
            }
        }
    }
    printf("Sorted array:\n");
    for(int i=0;i<n;i++) {
        printf("%s\n",arr[i]);
    }
}
int main(){
    swap();
    sortarrofstr();
    return 0;
}