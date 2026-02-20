/*
5. State Machine Implementation
Implement a basic state machine (initState, runState, stopState, errorState) with each state represented by a separate function.
Use function pointers to transition between states based on user input or internal conditions.
Demonstrate state transitions clearly in your program’s output.

6. Event Handling System
Define events such as buttonPressEvent, sensorTriggerEvent.
Implement handler functions for these events.
Log Session an array of function pointers mapping each event to its corresponding handler function.
Simulate event triggers, calling the appropriate handler through function pointers.
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
/*State Machine Implementation */
typedef void (*operation_t)(void);
void initState(void){
    printf("[State Machine] : init state....\ncompleted success\n");
    return;
}
void runState(void){
    printf("[State Machine] : Run State....\ncompleted success\n");
}
void stopState(void){
    printf("[State Machine] : stop state....\ncompleted success\n");
}
void errorState(void){
    printf("[State Machine] : Error state....\ncompleted success\n");
}
void control_state_machine(void){
    operation_t func_ptr[4]={initState,runState,stopState,errorState};
    int idx;
    printf("___Mechine States___\n1.init\n2.run\n3.stop\n4.error\nyour choice:");
    scanf("%d",&idx);
    if(idx<0 || idx>4){
        printf("No such state present....\nDefaulted to ERROR STATE\n");
        func_ptr[3]();
    }
    else{
        func_ptr[idx-1]();
    }
    return;
}

/* Event Handling System */
typedef void (*handler_t)(void);
static bool LED=false;
void buttonPressEvent(void){
    printf("[Event : button] : Button Press\n");
    LED^=1?printf("LED: on\n"):printf("LED : off\n");
}
void sensorTriggerEvent(void){
    printf("[Event: sensor]: Sensor data:%d\n",rand()%100);
}
void EvenHandling(void){
    char ch;
    handler_t table[]={buttonPressEvent,sensorTriggerEvent};
    printf("b.button press event\ns.sensor trigger\ne.exit\nEnter your option:");
    while((ch=getchar())!='\n');
    scanf("%c",&ch);
    if(ch=='b') table[0]();
    else if(ch=='s') table[1]();
    else if(ch=='e'){
        printf("Exit...success 1, failure 0\n");
        return;
    }
    else{
        printf("Invalid option...failure 1, success 0\n");
    }
}
int main(){
    control_state_machine();
    EvenHandling();
    return 0;
}