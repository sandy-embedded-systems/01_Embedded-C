/*
Exercise 16: Safe Memory Allocation Check
Goal: Practice error-checking after allocation.

Activity:

Try allocating a large chunk of memory (e.g., 1GB).
Check if the pointer is NULL.
If successful, print a success message.
If failed, handle the error gracefully.
Free if allocation succeeded.

Exercise 17: Struct Array with Dynamic Allocation
Goal: Allocate memory for array of structs.

Activity:

Define a struct (e.g., name and age).
Ask user how many entries to store.
Allocate memory using malloc.
Accept values and display them.
Free the memory
*/

#include<stdio.h>
#include<stdlib.h>

/* safe Memory Allocation Check */
void safe_mem_alloc(void){
    char *buff=NULL;
    buff=calloc(1,(1<<29));
    if(buff==NULL){
        printf("Memory allocation failed\n\n");
        return;
    }
    else printf("success\n\n");
    free(buff);
}

/* Struct Array with Dynamic Allocation */
typedef struct sample{
    char name[50];
    int age;
}sample_t;
void struct_arr_dma(void){
    int size;
    printf("How many entries required:");
    scanf("%d",&size);
    if(size<=0){
        printf("array with given size not possible\n\n");
        return;
    }
    sample_t entries[size];
    for(int i=0;i<size;i++){
        printf("Entry %d:",i);
        printf("Enter name:");
        scanf("%s",entries[i].name);
        printf("enter age:");
        scanf("%d",&entries[i].age);
    }
    printf("\n Your entries: \n");
    for(int i=0;i<size;i++){
        printf("Entry %d\n:",i);
        printf("name:%s\nage :%d\n",entries[i].name,entries[i].age);
    }
    return;
}
int main(){
    safe_mem_alloc();
    struct_arr_dma();
    return 0;
}