/*
8. Print the reverse of a string using recursion.
Input: "hello"
Output: "olleh"

9. Print all permutations of a given string. All possible arrangements of characters should be printed.
Input: "ABC"
Output: "ABC", "ACB", "BAC", "BCA", "CAB", "CBA"
*/

#include<stdio.h>
/*Print the reverse of a string using recursion*/
void reverse(char *str)
{
    if (*str=='\0')
        return;
    reverse(str+1); 
    printf("%c",*str);
}

/*Print all permutations of a given string */
void swap(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}
void permute(char *str,int l,int r)
{
    if(l==r)
    {
        printf("%s\n",str);
        return;
    }
    for(int i=l;i<=r;i++)
    {
        swap(&str[l],&str[i]);         
        permute(str,l+1,r);          
        swap(&str[l],&str[i]);       
    }
}
int main()
{
    char str[20]="ABC";
    reverse(str);
    permute(str,0,strlen(str)-1);
    return 0;
}
