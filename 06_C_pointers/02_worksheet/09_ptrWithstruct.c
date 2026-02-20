/*
9. Pointer and Structures
Goal: Use pointers to access and modify structure members efficiently, including passing structures to functions.

Activity:

Define a structure and create a pointer to it.
Use the pointer to read and modify structure members.
Pass structure pointers to functions that update structure data.
Dynamically allocate memory for structures and handle them via pointers.
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct student{
	char name[40];
	int id;
	float percentage;
}st;

void print(st *ptr)
{
	printf("Name      :%s\nId        :%d\npercentage:%.2f\n",ptr->name,ptr->id,ptr->percentage);
}
st *dynamicData(void){
	st *p=NULL;
	p=malloc(sizeof(st));
	if(p!=NULL){
		printf("Enter name:");
		scanf("%s",p->name);
		p->id=rand()%100+10001;
		printf("Enter percentage:");
		scanf("%f",&p->percentage);
	}
	else{
		printf("ERROR:Memory allocation failed\n\n");
		exit(EXIT_FAILURE);
	}
	return p;
}
int main(){
	st roll_01={"santhosh",10000,77.5};
	st *ptr=&roll_01;
	print(ptr);
	ptr=dynamicData();
	print(ptr);
}

