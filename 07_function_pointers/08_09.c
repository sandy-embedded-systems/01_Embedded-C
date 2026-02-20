/*
8. Generic Find Function
Implement a generic function find that takes an integer array, its size, and a function pointer as a condition.
Log Session condition functions (e.g., isEven, isPositive, isPrime).
Use find to identify and print the first element matching the provided condition.

9. Dynamic Logging Mechanism
Implement three logging functions (consoleLog, fileLog, networkLog) with a common signature.
Allow the program to select the appropriate logging method dynamically through function pointers.
Demonstrate switching between logging methods at runtime based on user input.
 */

#include<stdio.h>
#include<stdbool.h>
/* Generic Find function */
typedef bool (*funcType_t)(int);
bool isEven(int n){
    if(n%2==0) return true;
    else return false;
}
bool isPositive(int n){
    if(n<0) return true;
    else return false;
}
bool isPrime(int n){
    int i=2;
    while(i<n){
        if(n%i==0) return false;
        i++;
    }
    return true;
}
void find(int *arr,int size,funcType_t fptr){
    for(int i=0;i<size;i++){
        if(fptr(arr[i])){
            printf("%d at index %d\n",arr[i],i);
            break;
        }
    }
}
/* Dynamic Logging Mechanism */
typedef void (*Logger)(const char *message);
void consoleLog(const char *message)
{
    printf("[Console] %s\n", message);
}
void fileLog(const char *message)
{
    FILE *fp=fopen("log.txt","a");
    if (fp==NULL)
    {
        perror("File open failed");
        return;
    }
    fprintf(fp,"[File] %s\n",message);
    fclose(fp);
}
void networkLog(const char *message)
{
    printf("[Network] Sending log: %s\n", message);
}
Logger selectLogger(int choice)
{
    switch (choice)
    {
        case 1: return consoleLog;
        case 2: return fileLog;
        case 3: return networkLog;
        default: return NULL;
    }
}
void user_interface(void){
    int choice;
    char msg[30];
    Logger log;
    printf("Enter message to log:");
    scanf("%s",msg);
    printf("1.console log\n2.file log\n3.network log\nYour choice:");
    scanf("%d",&choice);
    log=selectLogger(choice);
    if(log==NULL) printf("Invalid choice\n");
    else log(msg);
    return;
}
int main(){
    int arr[5]={2,44,-3,5,7};
    find(arr,5,isEven);
    find(arr,5,isPrime);
    find(arr,5,isPositive);
    user_interface();
    return 0;
}