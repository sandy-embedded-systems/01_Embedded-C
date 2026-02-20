/*
Exercise 10: Log Session and Reverse an Array
Goal: Use pointers to reverse dynamically allocated memory.

Activity:

Allocate an array of integers using malloc.
Accept n values.
Reverse the array using pointer arithmetic (not indexing).
Print reversed values.
Free the memory.

Exercise 11: Accept Characters Until Enter Pressed
Goal: Dynamically grow a string buffer with realloc.

Activity:

Start with a small buffer.
Accept characters one by one.
Reallocate buffer each time a new character is added.
Stop on newline character.
Null-terminate and print the string.
Free the memory.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Log Session and Reverse an Array */
void Log_reverse_array(void){
    int *arr=NULL,n;
    printf("Enter size:");
    scanf("%d",&n);
    if(n<=0){
        printf("array with given size is not possible\n\n");
        return;
    }
    arr=malloc(n*sizeof(int));
    if(arr==NULL){
        printf("Memory allocation failed\n\n");
        return;
    }
    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);
    for(int i=0,j=n-1;i<j;i++,j--)
        *(arr+i)^=(*(arr+j))^=(*(arr+i))^=(*(arr+j));
    printf("the reversed array: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    free(arr);
    return;
}

/* Accept Characters Until Enter Pressed */
void str_input(void){
    char *ptr=NULL,ch;
    int i=0;
    printf("\n\nEnter string:");
    while((ch=getchar())!='\n');
    ch=0;
    do{
        scanf("%c",&ch);
        ptr=realloc(ptr,i+1);
        ptr[i]=ch;
    }while(ptr[i++]!='\n');
    ptr[i-1]='\0';
    printf("%s\n",ptr);
    free(ptr);
    return;
}
int main()
{
    Log_reverse_array();
    str_input();
    return 0;
}