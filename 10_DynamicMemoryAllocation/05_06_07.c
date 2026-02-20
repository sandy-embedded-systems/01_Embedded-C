/*
Exercise 5: Reallocate an Array Dynamically
Goal: Use realloc to extend an array as needed.

Activity:

Allocate memory for 2 integers.
Ask the user for values.
Then resize the array to 5 integers using realloc.
Accept more values into the resized array.
Print all values.
Free the memory at the end.

Exercise 6: Log Session a Dynamic 2D Array
Goal: Learn how to allocate and access a 2D array dynamically.

Activity:

Ask the user for number of rows and columns.
Allocate memory for an array of row pointers.
Allocate each row separately using malloc.
Accept values for each row-column index.
Display the matrix.
Free each row and then the row pointer array.

Exercise 7: Dynamic String Input
Goal: Handle strings with dynamic memory allocation.

Activity:

Ask the user to enter a string.
Find its length using strlen.
Allocate memory to store the string using malloc.
Copy the string to the new memory.
Print the copied string.
Free the memory.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* Reallocate an Array Dynamically */
void realloc_arr(void){
    int *arr=malloc(2*sizeof(int));
    if(arr==NULL){
        printf("Memiry allocation failed\n\n");
        return;
    }
    printf("Enter 2 integerse:");
    scanf("%d%d",arr,arr+1);
    arr=realloc(arr,5);
    printf("Array resized to 5\nEnter 3 more elements:");
    scanf("%d%d%d",arr+2,arr+3,arr+4);
    printf("The array: ");
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");
    free(arr);
    return;
}

/* Log Session a Dynamic 2D Array */
void log2D_array(void){
    int rows,cols;
    printf("Enter number of rows: ");
    scanf("%d",&rows);
    printf("Enter number of columns: ");
    scanf("%d",&cols);
    int **matrix = (int **)malloc(rows*sizeof(int *));
    if (matrix==NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    for(int i=0;i<rows;i++)
    {
        matrix[i]=(int *)malloc(cols*sizeof(int));
        if (matrix[i]==NULL)
        {
            printf("Memory allocation failed for row %d!\n",i);
            return;
        }
    }
    printf("Enter elements:\n");
    for(int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            printf("Element [%d][%d]:",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("\nMatrix:\n");
    for (int i=0;i<rows;i++)
    {
        for (int j=0; j<cols;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0;i<rows;i++)
        free(matrix[i]);
    free(matrix);
    return;
}
/* Dynamic String Input */
void dynamic_str_input(void)
{
    char str[50],*ptr=NULL,ch;
    int len;
    printf("Enter a string:");
    while((ch=getchar())!='\n');
    scanf("%[^\n]s",str);
    len=strlen(str);
    ptr=malloc(len+1);
    strcpy(ptr,str);
    ptr[len]='\0';
    printf("%s",ptr);
}

int main(){
    realloc_arr();
    log2D_array();
    dynamic_str_input();
}
