/*
5. Dynamic Memory Allocation
Goal: Allocate, reallocate, and free memory dynamically for different data types and structures while avoiding memory leaks.

Activity:

Allocate memory for an array using malloc.
Expand or shrink the allocated memory using realloc.
Initialize the allocated memory using calloc.
Free allocated memory after use.
Handle cases where allocation fails.
 
6. Character Pointer and String Handling
Goal: Manipulate strings using character pointers and standard string library functions.

Activity:

Declare a character pointer and assign it to a string literal or dynamically allocated memory.
Use pointer arithmetic to traverse and modify the string.
Implement functions to concatenate, copy, or reverse strings using only pointers.
Understand how strings are stored and accessed in memory via pointers.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* Dynamic Memory Allocation */
void dynamicAllocation(void)
{
	int *m_arr=malloc(5*sizeof(int));// memory allocated for 5 ints
	if(m_arr==NULL){
		printf("Memory allocation Failed\n\n");
		exit(EXIT_FAILURE);
	}
	m_arr=realloc(m_arr,4*sizeof(int)); // shrink the array to 4 ints
	int *c_arr=calloc(5,sizeof(int));// memory allocated for 5 ints and initialized with 0's
	if(c_arr==NULL){
		printf("Memory allocation Failed\n\n");
                exit(EXIT_FAILURE);
        }
	free(m_arr);
	free(c_arr);
}
 
/* Character Pointer and String Handling */
char *mystrcat(char *dest, const char *src)
{
	char *temp=dest;
	while(*temp) temp++;
	while(*src)
		*temp++ = *src++;
	*temp='\0';
	return dest;
}
char *mystrcpy(char *dest,const char *src)
{
	int i;
	for(i=0;src[i];i++)
		dest[i]=src[i];
	dest[i]='\0';
	return dest;
}
void reverse(char *str){
	for(int i=0,j=strlen(str)-1;i<j;i++,j--){
		*(str+i)^=(*(str+j))^=(*(str+i))^=(*(str+j));
	}
}
void strManipulation(void)
{
	char str[]="Hello wordl!",dest[50]="Hi ";// string literal
	char *p=str; 
	for(int i=0;p[i];i++)
		printf("%c",*(p+i));
	printf("\n");
	printf("concatination:\n%s\n",mystrcat(dest,str));
	printf("copy:\n%s\n",mystrcpy(dest,str));
	reverse(str);
	printf("reverse:\n%s\n",str);
}
int main(){
	dynamicAllocation();
	strManipulation();
}
