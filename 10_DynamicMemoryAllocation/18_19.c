/*
Exercise 18: Insert Element at Any Position
Goal: Modify dynamic array and shift elements.

Activity:

Allocate memory for an array.
Accept n values.
Ask user to insert a value at a specific position.
Use realloc to increase size.
Shift elements and insert new value.
Print final array and free memory.

Exercise 19: Dynamic Array of Pointers to Integers
Goal: Work with array of pointers using malloc.

Activity:

Ask user for count.
Allocate array of int* pointers.
Use malloc to assign an integer for each pointer.
Assign and print values.
Free all integers and the array.

*/

#include <stdio.h>
#include <stdlib.h>

int *insert(int *arr,int *n){
    int value,position;
    printf("Enter value to insert: ");
    scanf("%d",&value);
    printf("Enter position (0 to %d):",*n);
    scanf("%d",&position);
    if (position<0 ||position>(*n)) {
        printf("Invalid position!\n");
        return arr;
    }
    int *temp=realloc(arr,(*n+1)*sizeof(int));
    if (temp==NULL){
        printf("Reallocation failed!\n");
        return arr;
    }
    arr=temp;
    for(int i=*n;i>position;i--) {
        arr[i]=arr[i-1];
    }
    arr[position]=value;
    *n++;
    return arr;
}
void insertEleAtPos(void){
    int *arr;
    int n,i,value,position;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    if (arr==NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter %d elements:\n", n);
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    insert(arr,&n);
    printf("Array after insertion:\n");
    for (i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n\n");
    free(arr);
    return;
}

/*Dynamic Array of Pointers to Integers*/
void array_of_ptrs(void){
    int cnt;
    printf("Enter count:");
    scanf("%d",&cnt);
    if(cnt<=0){
        printf("Invalid size given\n\n");
        return;
    }
    int *arr[cnt];
    for(int i=0;i<cnt;i++){
        arr[i]=malloc(sizeof(int));
        printf("enter value for index %d:",i);
        scanf("%d",arr[i]);
    }
    printf("the entered values: ");
    for(int i=0;i<cnt;i++){
        printf("%d ",*arr[i]);
    }
    for(int i=0;i<cnt;i++)
        free(arr[i]);
    printf("\n\n");
    return;
}
int main() {
    insertEleAtPos();
    array_of_ptrs();
}
