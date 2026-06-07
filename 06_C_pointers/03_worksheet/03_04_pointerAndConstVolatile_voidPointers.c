/*
3. Working with Const and Volatile Pointers
Goal: Demonstrate how const and volatile qualifiers affect pointer behavior in hardware register access.
Activity:

Define a dummy hardware register address using #define:
#define REG_BASE 0x40000000
Declare pointers with different qualifiers:
volatile uint32_t *reg_modifiable = (uint32_t *)REG_BASE;
const uint32_t *reg_readonly = (const uint32_t *)REG_BASE;
const volatile uint32_t *reg_const_volatile = (const volatile uint32_t *)REG_BASE;
Attempt to write to and read from each pointer and note compiler behavior.

4. Void Pointers and Memory Copying
Goal: Use void pointers to create a generic memory copying utility function for embedded data types.
Activity: 
Declare a function mem_copy(void *dest, const void *src, size_t n) that copies n bytes from src to dest:
1
void mem_copy(void *dest, const void *src, size_t n);
Within the function, use char * pointers to copy data byte-by-byte.
Test the function by copying an array of integers and an array of floats.
*/
#include<stdio.h>
#include<stdint.h>
/* Void Pointers and Memory Copying */
void mem_copy(void* dest,const void *src, size_t n)
{
    int i=0;
    char *s=(char*)src,*d=(char*)dest;
    while(i<n){
        d[i]=s[i];
        i++;
    }
}
void test_mem_copy(void){
    int arr[5]={1,2,3,4,5},brr[5];
    float f1[]={1.2,3.4,5.6,7.8,33.5},f2[5];
    mem_copy(brr,arr,20);
    printf("Copied array of ints:");
    for(int i=0;i<5;i++)
        printf("%d ",brr[i]);
    printf("\ncopied array of floats:");
    mem_copy(f2,f1,20);
    for(int i=0;i<5;i++)
        printf("%.3f ",f2[i]);
    printf("\n\n");
}

/* Working with Const and Volatile Pointers */
void function(void){
    char *buff=calloc(1,sizeof(int));
    *(int*)buff=40;
#ifndef REG_BASE
    #define REG_BASE buff
#endif
    /* A volatile pointer is very common in embedded, when declared, the pointer is normal but it is pointing to
       volatile data. sometimes the data has to modified externally( like DMA,UART hardware, etc.) ,in such situation
       every read for the data will be guranteed to be done.*/
    volatile uint32_t *reg_modifiable=(uint32_t *)REG_BASE;
    *reg_modifiable=10;

    /* here the pointer is pointing to a constant data, pointer can be modifiable but bot the data */
    const uint32_t *reg_readonly=(const uint32_t*)REG_BASE;
    // *reg_readonly=30; // this results in compile time error

    /* here the pointer is pointing to constant volatile data, i.e, software cannot modify data but externally it
      may be modified. and the pointer us normal, you can change its pointing location*/
    const volatile uint32_t *reg_const_volatile=(const volatile uint32_t*)REG_BASE;
    

}
int main()
{
    test_mem_copy();
    function();
}
