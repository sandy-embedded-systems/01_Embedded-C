/*
4. Function Pointers in Structures
Goal
Learn how to include and use function pointers inside structures for callback mechanisms and dynamic behavior in embedded systems.

Activity
Define a structure containing function pointers.
Initialize it with different functions and invoke them.
Use this setup to simulate a hardware driver interface with different behavior implementations.
Demonstrate dynamic assignment and execution of function pointers based on a condition or input.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 100
#define E_MEMFAIL 1
typedef struct HardWare{
    int (*init)(void);
    int (*send)(char*,size_t);
    int (*receive)(char*,int);
    void (*close)(void);
}driver_t;
static char *buff;
static int cur_len=0;
int init_hardware(void){
    buff=calloc(1,LEN);
    if(buff==NULL) return -E_MEMFAIL;
    else return LEN;
}
int send_data(char *data,size_t size){
    if(size<0 || size>LEN) return -1;
    else{
        memcpy(buff,data,size);
        cur_len=size;
        return size;
    }
}
int receive_data(char *data,int size){
    if(size<0 || size>cur_len) return -1;
    else{
        memcpy(data,buff,size);
        memmove(buff,buff+size,strlen(buff+size+1));
        cur_len-=size;
        buff[cur_len]='\0';
        return size;
    }
}
void shut_down(void){
    free(buff);
    printf("Hardware saved successfully\n");
    return;
}
static driver_t operations={
    .init=init_hardware,
    .send=send_data,
    .receive=receive_data,
    .close=shut_down
};
int main(){
    char msg[50];
    printf("Enter message:");
    scanf("%s",msg);
    operations.init();
    operations.send(msg,strlen(msg));
    printf("data in hardware:\n%s\n",buff);
    memset(msg,'\0',50);
    operations.receive(msg,10);
    printf("data in hardware:\n%s\n",buff);
}


