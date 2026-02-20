/*
Exercise 14: Tokenize String Dynamically
Goal: Store each word of a sentence in dynamically allocated memory.

Activity:

Accept a sentence as input.
Use strtok() to split it into words.
Use malloc to copy each token into a new memory block.
Store them in a pointer array.
Print all words and free each block.

Exercise 15: Dynamic Menu-Driven Array
Goal: Handle operations on a dynamic array with growing size.

Activity:

Start with an empty array.
Provide a menu with options: Add element, Display, Exit.
Use realloc each time user adds an element.
Print array contents.
Free memory on exit.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* Tokenize String Dynamically */
void tokanize(void){
    char str[100],*p;
    int idx=0;
    char *ptr[20]={0};
    printf("Enter string:");
    scanf("%[^\n]s",str);
    for(p=str;p=strtok(p," ");){
        ptr[idx]=calloc(1,strlen(p)+1);
        strcpy(ptr[idx],p);
        idx++;
        p=NULL;
    }
    for(int i=0;i<idx;i++){
        printf("token %d: %s\n",i,ptr[i]);
    }
    printf("\n\n");
}

/* Dynamic Menu-Driven Array */
int* add_element(int *arr,int *size){
    int num;
    printf("Enter element:");
    scanf("%d",&num);
    arr=realloc(arr,(*size+1)*sizeof(int));
    *size++;
    arr[*size]=num;
    return arr;
}
void display(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}
void menu_array(void){
    int size=0,choice,*arr=NULL;
    while(1){
        printf("1.add element\n2.display\n3.exit\nenter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            arr=add_element(arr,&size);
            break;
        case 2:
            display(arr,size);
            break;
        case 3:break;;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    free(arr);
    return;
}
int main(){
    tokanize();
    menu_array();
    return 0;
}