#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*11*/
void matrix_multiplication(void){
    int a[10][10],b[10][10],c[10][10];
    int r1,c1,r2,c2,i,j,k;
    printf("Enter rows and columns of matrix A: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter rows and columns of matrix B: ");
    scanf("%d %d",&r2,&c2);
    if (c1 !=r2){
        printf("Matrix multiplication not possible\n");
        return;
    }
    printf("Enter elements of matrix A:\n");
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            scanf("%d",&a[i][j]);
    printf("Enter elements of matrix B:\n");
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            scanf("%d",&b[i][j]);
    for(i=0;i<r1;i++) {
        for(j=0;j<c2;j++) {
            c[i][j] = 0;
            for(k=0;k<c1;k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Result Matrix:\n");
    for(i=0;i<r1;i++) {
        for(j=0;j<c2;j++) {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return;
}
/*23*/
void print_star_pattern(int n){
    int i,j;
    for(i=1;i<=n;i++){
        if(i%2==0){
            for(j=1;j<=i;j++) j%2==0?printf("*"):printf(" ");
        }
        else{
            for(j=1;j<=i;j++) j%2==0?printf(" "):printf("*");
        }
        printf("\n");
    }
    for(i=n-1;i>=0;i--){
        if(i%2==0){
            for(j=1;j<=i;j++) j%2==0?printf("*"):printf(" ");
        }
        else for(j=1;j<=i;j++) j%2==0?printf(" "):printf("*");
        printf("\n");
    }
}

/* 24*/
void print_num_pattern(int n){
    int prev=0,prev2=0,curr=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            printf("%d ",curr);
            prev=curr;
            curr=prev+prev2;
            prev2=prev;
        }
        printf("\n");
    }
}
/*25*/
void print_pattern(int n){
    int i,j;
    if(n<0) n=-n;
    for(i=1;i<=n;i++){
        for(j=1;j<n-i+1;j++) printf(" ");
        for(j=1;j<=i;j++){
            printf("%d",j);
        }
        for(j=i-1;j>=1;j--) printf("%d",j);
        printf("\n");
    }
    for(i=n-1;i>=1;i--){
        for(j=1;j<n-i+1;j++) printf(" ");
        for(j=1;j<=i;j++) printf("%d",j);
        for(j=i-1;j>=1;j--) printf("%d",j);
        printf("\n");
    }
}

/*12*/
void remDupsSorted(int *arr,int *size){
    int i,j;
    for(i=0;i<(*size)-1;i++){
        if(arr[i]==arr[i+1]){
            memmove(arr+i,arr+i+1,(*size-i-1)*sizeof(int));
            *size=*size-1;
        }
    }
}
void print(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return;
}
/* 13*/
void boundary_elements(int row,int col,int arr[][col])
{
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(j==0 || j==row-1 || j==col-1|| i==0) printf("%d ",arr[i][j]);
        }
    }
    printf("\n");
}
/* 14*/
void largest(int *arr,int size){
    int large=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>large) large=arr[i];
    }
    printf("Largest:%d\n",large);
}
/* 16*/
void swap(void){
    int a=10,b=20;
    printf("Before swap:\na=%d  b=%d\n",a,b);
    a^=b^=a^=b;
    printf("After swap:\na=%d  b=%d\n",a,b);
}

/*17*/
void print_bin(void){
    char ch;
    int start,end;
    
    printf("Enter byte:");
    printf("%c",&ch);
    while((ch=getchar())!='\n');
    printf("Enter start:");
    scanf("%d",&start);
    printf("Ennter end:");
    scanf("%d",&end);
    
    if(start<0|| end>=8) printf("Byte boundary exceeded\n");
    else{
        if(start>end) start^=end^=start^=end;
        while(start<=end){
            printf("%d",(ch>>start)&1);
            start++;
        }
    }
}

/*18*/
void perfect_number(int n){
    int sum=0,temp=n;
    while(temp){
        sum+=temp%10;
        temp/=10;
    }
    if(sum==n) printf("\n%d is a perfect number\n",n);
    else printf("\n%d is not a perfect number\n",n);
    return;
}
/*19*/
typedef void (*fptr)(int);

void print_num(int n){
    printf("received:%d\n",n);
    return;
}
void function_ptr_task(fptr operation){
    operation(10);
}

/*20*/
void sum_of_elements(int size){
    int *arr=NULL,sum=0;
    arr=(int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++){
        scanf("%d",arr+i);
        sum+=arr[i];
    }
    printf("Sum of elements:%d\n",sum);
    return;
}
void swap_bytes(void){
    int num;
    printf("Enter num:");
    scanf("%x",&num);
    printf("Before byte swap:%x\n",num);
    unsigned int b1=(num&0xFF);       
    unsigned int b2=(num&0xFF00); 
    num=num&0xFFFF0000;           
    num|=(b1 << 8);                     
    num|=(b2 >> 8);                    
    printf("After byte swap:%x\n",num);
}

/*21*/
typedef struct Node{
    int data;
    struct Node* next;
}node;
void remDuplicatesInList(node *head)
{
    node *curr=head,*temp;
    while (curr!=NULL && curr->next!=NULL)
    {
        if (curr->data==curr->next->data)
        {
            temp=curr->next;
            curr->next=temp->next;
            free(temp);
        }
        else curr=curr->next;
    }
}
node *insert(node* head){
    node *new=calloc(1,sizeof(node));
    printf("enter data:");
    scanf("%d",&new->data);
    if(head==NULL) head=new;
    else{
        node *temp=head;
        while(temp->next)
            temp=temp->next;
        temp->next=new;
    }
    return head;
}
void print_list(node *head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    return;
}
void ListTask(void){
    node *head=NULL;
    for(int i=0;i<5;i++){
        head=insert(head);
    }
    //print_list(head);
    remDuplicatesInList(head);
    print_list(head);
}
/*22*/
node* reverseK(node* head, int k)
{
    node *current=head;
    node *prev=NULL;
    node *next=NULL;
    int count=0;
    while(current!=NULL && count<k)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    if(next!=NULL)
        head->next=reverseK(next,k);
    return prev;
}
void ListTask2(void){
    node *head=NULL;
    for(int i=0;i<6;i++){
        head=insert(head);
    }
    reverseK(head,3);
    print_list(head);
}
int main(){
    int arr[]={1,2,2,3,4,5};
    int size=6;
    int matrix[][3]={1,2,3,4,5,6,7,8,9};
    int m2[][3]={1,2,3,4,5,6,7,8,9};
    print_num_pattern(5);
    print_star_pattern(5);
    print_pattern(5);
    remDupsSorted(arr,&size);
    print(arr,size);
    boundary_elements(3,3,matrix);
    swap();
    largest(arr,size);
    print_bin();
    perfect_number(5);
    swap_bytes();
    function_ptr_task(print_num);
    ListTask();
    ListTask2();
    matrix_multiplication();
}