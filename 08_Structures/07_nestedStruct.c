/*
7. Nested Structures and Arrays within Structures
Goal
Explore how to organize complex data using nested structures and how to embed arrays inside structures for buffer management.

Activity
Log Session a structure with another structure as a member.
Log Session an array of structures to hold multiple sensor values.
Include arrays within a structure to buffer a set of samples.
Model a protocol layer with header and payload sub-structures.
*/
#include<stdio.h>
#define RUNNING 1
#define STOP 0
typedef struct outter{
    char sensor_name[50];
    struct inner{
        float value;
        char state;
    }readings;
}out_t;

void show_data(out_t *arr){
    for(int i=0;i<5;i++){
        if(arr[i].readings.state){
            printf("sensor name:%s\nsnesor value:%d\n",arr[i].sensor_name,arr[i].readings.value);
        }
    }
}
void nested_struct(void){
    out_t sensors[5];
    for(int i=0;i<5;i++){
        printf("Sensor %d\n",i+1);
        printf("Enter sensor name:");
        scanf("%s",sensors[i].sensor_name);
        printf("Enter value:");
        scanf("%d",&sensors[i].readings.value);
        if(i%2==0) sensors[i].readings.state=RUNNING;
        else sensors[i].readings.state=STOP;
    }
    show_data(sensors);
}
int main(){
    nested_struct();
    return 0;
}
