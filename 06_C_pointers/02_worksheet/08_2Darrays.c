/*
8. Pointer and Multi-Dimensional Arrays
Goal: Access and manipulate elements of multi-dimensional arrays using pointers and pointer arithmetic.

Activity:

Declare a 2D array.
Use pointers to iterate through rows and columns.
Implement operations such as matrix transpose or addition using pointer arithmetic only.
Pass multi-dimensional arrays as pointers to functions and manipulate elements.
*/

#include<stdio.h>
void input(int rows,int cols,int (*arr)[cols])
{
    for(int i=0;i<rows;i++){
        printf("Row%d:",i);
        for(int j=0;j<cols;j++)
            scanf("%d",&arr[i][j]);
    }
}
void transpose(int r1,int c1,int (*arr1)[c1])
{
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++)
            printf("%d ",arr1[j][i]);
        printf("\n");
    }
}
void addtion(int (*arr1)[3],int (*arr2)[3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",arr1[i][j]+arr2[i][j]);
        }
        printf("\n");
    }
}
void ptrWithMutliDimeArr(void){
    int matrix1[3][3],matrix2[3][3];
    input(3,3,matrix1);
    input(3,3,matrix2);
    transpose(3,3,matrix1);
    addtion(matrix1,matrix2);
}
int main(){
    ptrWithMutliDimeArr();
    return 0;
}

