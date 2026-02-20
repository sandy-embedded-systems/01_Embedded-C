/*
9. Function Returning Pointer to Fixed-Size Array
Goal: Implement a function that returns a pointer to a fixed-size calibration data array.
Activity:
Use typedef to declare a pointer to an array of 10 integers:
typedef int (*CalibArrayPtr)[10];
Log Session a function that returns a pointer to a static array of calibration values:
CalibArrayPtr get_calibration_data(void);
From the calling function, access calibration data via the returned pointer.

10. Pointer Arithmetic on Struct Arrays
Goal: Access and modify an array of peripheral register structs using pointer arithmetic.
Activity: 
Define a struct representing peripheral registers:
struct Peripheral {
  uint8_t status;
  uint8_t control;
  uint16_t data;
};
Declare an array of 5 such structs.
Use a pointer to traverse and modify the array elements using pointer arithmetic.
*/

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
struct Peripheral {
  uint8_t status;
  uint8_t control;
  uint16_t data;
}; 

/* Function Returning Pointer to Fixed-Size Array */
typedef int (*calibArrayPtr)[10];
calibArrayPtr get_calibration_data(void){
    calibArrayPtr ptr=malloc(sizeof(*ptr));
    printf("Enter elements:");
    for(int i=0;i<10;i++){
        scanf("%d",&((*ptr)[i]));
    }
    return ptr;
}
void test_calibArrayPtr(void){
    calibArrayPtr ptr;
    ptr=get_calibration_data();
    printf("Array elements:");
    for(int i=0;i<10;i++){
        printf("%d ",(*ptr)[i]);
    }
    printf("\n\n");
}
/* Pointer Arithmetic on Struct Arrays */
void arraOfStruct(void){
    struct Peripheral arr[5];
    struct Peripheral *ptr=arr;
    for(int i=0;i<5;i++){
        printf("Enter mode %d\n:status,control and data:",i);
        scanf("%d%d%d",&ptr->status,&ptr->control,&ptr->data);
        ptr++;
    }
    printf("Current starus:\n");
    ptr=arr;
    for(int i=0;i<5;i++){
        printf("Mode %d:\n",i);
        printf("status:%d\ncontrol:%d\ndata:%d\n\n",ptr->status,ptr->control,ptr->data);
    }
}
int main()
{
    arraOfStruct();
    test_calibArrayPtr();
}