/*
 *
9. Question: Insert element at position
Question description: Write a C program to insert a number at a given position in an array.
Sample data:
Array: 10 20 30 40
Insert: 25 at position 2
Expected output:
Array after insertion: 10 20 25 30 40

10. Question: Delete element at position
Question description: Write a C program to delete a number at a given position in an array.
Sample data:
Array: 10 20 30 40
Delete at position: 2
Expected output:
Array after deletion: 10 20 40

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void print(int*,int);
void insert(int *p,int size)
{
	int data,pos;
	printf("Enter position:");
	scanf("%d",&pos);
	if(pos<0){
		printf("Invalid index choosed...\nNote: Index cannot be negative.....\n\n");
	}
	else if(pos>size){
		printf("Invalid index\nNote: Idex is outof range.....\n");
	}
	else{
		printf("Enter data:");
		scanf("%d",&data);
		p[pos]=data;
	}
}
void delete(int *p,int size){
	int pos;
	 printf("Enter position:");
        scanf("%d",&pos);
        if(pos<0){
                printf("Invalid index choosed...\nNote: Index cannot be negative.....\n\n");
        }
        else if(pos>size){
                printf("Invalid index\nNote: Idex is outof range.....\n");
        }
        else{
                p[pos]=0;
        }
}

void sortAscending(int *p,int size){
	for(int i=0;i<size-1;i++){
		for(int j=i;j<size;i++){
			if(p[j]>p[j+1]){
				p[j]^=p[j+1]^=p[j]^=p[j+1];
			}
		}
	}
	return;
}
int main(){
	int arr[20]={0},size=20,choice;
	while(1){
		printf("1.insert\n2.delete\n3.sort in ascending\n4.sort in descending\n5.print array \n6.exit\nyour choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:insert(arr,size);
			       break;
			case 2:delete(arr,size);
			       break;
			      break;
			case 5:print(arr,size);
			       break;
			case 6:exit(0);
			default:printf("Invalid choice\nTry again......\n\n");
		}
	}
}

void print(int *p,int size){
	for(int i=0;i<size;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}
