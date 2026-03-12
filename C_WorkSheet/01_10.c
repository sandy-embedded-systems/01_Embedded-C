#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
/*1*/
void nthFiboNum(int n){
    int a,b,res;
    a=0,b=1;
    for(int i=0;i<n;i++){
        res=a+b;
        a=b;
        b=res;
    }
    printf("%d\n",a);
}

/*2*/
void change_case(char *str){
    int choice;
    printf("1.Upper case   2.lower case\nEnter your choice:");
    scanf("%d",&choice);
    if(choice==1){
        for(int i=0;str[i];i++){
            if(islower(str[i])) str[i]-=32;
        }
    }
    else{
        for(int i=0;str[i];i++){
            if(isupper(str[i])) str[i]+=32;
        }
    }
    return;
}

/*3*/
void dec_to_hex(int n){
    int i,j,cnt;
    for(i=31;i>=0;){
        cnt=0;
        for(j=0;j<4;j++){
            cnt=cnt+((n>>i)&1)*(1<<j);
            i--;
        }
        if(cnt<=9) printf("%d",cnt);
        else{
            switch(cnt){
                case 10:printf("a");
                break;
                case 11:printf("b");
                break;
                case 12:printf("c");
                break;
                case 13:printf("d");
                break;
                case 14:printf("e");
                break;
                case 15:printf("f");
                break;
            }
        }
    }
}

/*4*/
void isAmstrong(int n){
    int temp=n,sum=0,x;
    while (temp)
    {
        x=temp%10;
        sum+=(x*x*x);
        temp/=10;
    }
    if(sum==n) printf("\n%d is amstrong number\n",n);
    else printf("\n%d is not an amstrong number\n",n);
}
/*5*/
void concat(char *s1,char *s2){
    if(*s1=='\0')
    {
        if(*s2=='\0') return;
        *s1=*s2;     
        concat(s1+1,s2+1);
    }
    else concat(s1+1,s2);
}

/*6*/
void revNumRecursion(int n){
    if(n==0) return;
    printf("%d",n%10);
    revNumRecursion(n/10);
}
/* 7.*/
void interchange(int *arr,int size){
    int max=arr[0],min=arr[0],min_idx=0,max_idx=0;
    for(int i=0;i<size;i++){
        if(min>arr[i]){
            min=arr[i];
            min_idx=i;
        }
        if(max<arr[i]){
            max=arr[i];
            max_idx=i;
        }
    }
    if(min_idx==max_idx) return;
    else{
        arr[min_idx]^=arr[max_idx]^=arr[min_idx]^=arr[max_idx];
        printf("\nchnged\n");
    }
    return;
}
/*8.*/
void remDuplicates(int *arr,int *size){
    int i,j;
    for(i=0;i<*size-1;i++){
        for(j=i+1;j<*size;j++){
            if(arr[i]==arr[j]){
                memmove(arr+j,arr+j+1,(*size-j+1)*sizeof(int));
                *size--;
            }
        }
    }
}
/*10*/
void revNum(int n){
    int temp=n,num=0,i=0,test=0;
    if(n<=999) return;
    while (i!=3)
    {
        num=num*10+temp%10;
        temp/=10;
        i++;
    }
    temp=num;
    while (temp)
    {
        test=test*10+temp%10;
        temp/=10;
    }
    n-=test;
    n+=num;
    printf("%d\n",n);
    
}
void print(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return;
}
/*9*/
void sorting_string()
{
    int n,i,j;
    char **arr, temp[100];
    printf("Enter number of strings: ");
    scanf("%d", &n);
    arr=(char **)malloc(n*sizeof(char *));
    for(i=0;i<n;i++)
        arr[i]=(char*)malloc(100*sizeof(char));
    printf("Enter strings:\n");
    for(i=0;i<n;i++){
        scanf("%s",arr[i]);
    }
 
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++)
        {
            if(strcmp(arr[i],arr[j])>0)
            {
                strcpy(temp,arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j],temp);
            }
        }
    }
    printf("\nSorted strings:\n");
    for(i=0;i<n;i++)
        printf("%s\n",arr[i]);
 
    for(i=0;i<n;i++)
        free(arr[i]);
    free(arr);
    return;
}

int main(){
    char str[]="Hello";
    int arr[]={1,2,3,3,4,5};
    int size=6;
    dec_to_hex(10);
    isAmstrong(1);
    change_case(str);
    printf("%s\n",str);
    interchange(arr,5);
    remDuplicates(arr,&size);
    print(arr,size);
    revNum(1699);
    revNumRecursion(1);
    nthFiboNum(2);
    sorting_string();
    return 0;
}