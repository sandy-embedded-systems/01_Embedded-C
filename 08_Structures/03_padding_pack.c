/*
3. Structure Padding, Alignment, and Packing
Goal
Understand how padding affects structure size and how to control layout using packing directives.

Activity 
Log Session a structure with mixed data types (char, int, short).
Check the size and member offsets using sizeof() and pointer arithmetic.
Reorder members to reduce padding and observe the change in size.
Use #pragma pack(1) and compare memory layout.
Simulate a communication packet where field alignment matters.
*/

#include<stdio.h>
typedef struct sample_1{
    char ch;
    int n;
    short int s;
}sample_1;
typedef struct sample_2{
    int n;
    short int s;
    char ch;
}sample_2;
#pragma pack(1)
struct sample_3{
    char ch;
    int n;
    short int s;
};
#pragma pack(1)
typedef struct sample_packet{
    unsigned char addr;
    short int id;
    unsigned int data;
}Packet;
void simulate_packet(void){
    Packet p={.addr=0xAA,.id=22,.data=0x1234};
    printf("size of packet:%ld\n",sizeof(p));
    printf("Frame: ");
    char *ptr=(char*)&p;
    for(int i=0;i<sizeof(p);i++){
        printf("%x ",ptr[i]);
    }
}
int main(){
    sample_1 obj_no_allign;
    sample_2 obj_allign;
    printf("strcut size without allignment:%ld\nstrcut size with allignment:%d\n",sizeof(sample_1),sizeof(sample_2));
    printf("struct size with padding:%ld\n",sizeof(struct sample_3));
    simulate_packet();
}
