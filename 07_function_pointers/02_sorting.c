/*
2. Sorting Algorithms Selector
Implement three sorting functions (bubbleSort, selectionSort, insertionSort) that sort an integer array.
Store pointers to these sorting functions in an array of function pointers.
Prompt the user to choose a sorting method, and use the selected function pointer to sort a user-provided integer array.
*/
#include<stdio.h>
#include<stdlib.h>
typedef void (*sort_table)(int*,int);
void bubbleSort(int *arr, int n){
    int i,j;
    n--;
    for(i=0;i<n;i++){
        for(j=0;j<(n-i);j++){
            if(arr[j+1]<arr[j])
                arr[j+1]^=arr[j]^=arr[j+1]^=arr[j];
        }
    }
}
void selectionSort(int *arr,int n){
    int i,j,min;
    for(i=0;i<(n-1);i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[j+1])
                min=j;
        if(min!=i){
            arr[min]^=arr[i]^=arr[min]^=arr[i];
        }
    }
}
void insertionSort(int *arr,int n){
    int key,i,j;
    for(i=1;i<n;i++){
        key=arr[i];
        for(j=i-1;j>=0 && arr[j]>key;j--)
            arr[j+1]=arr[j];
        arr[j+1]=key;
    }
}
int main()
{
    int choice;
    sort_table table[]={bubbleSort,selectionSort,insertionSort};
    int arr[10];
    printf("The array: ");
    for(int i=0;i<10;i++)
        printf("%d ",arr[i]=rand()%200);
    printf("\n");
    printf("1.bubble sort\n2.selection sort\n3.insertion sort\nchoose option:");
    scanf("%d",&choice);
    if(choice<1 && choice>=4){
        printf("No such option provided...process denied\n");
        return 0;
    }
    table[choice-1](arr,10);
    printf("Sorted array: ");
    for(int i=0;i<10;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}