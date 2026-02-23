/*
Merge alternate lines from two files into a third file.
Input: File 1: a.txt (A1, A2)
File 2: b.txt (B1, B2)
New file: merge.txt
Output: merge.txt: A1, B1, A2, B2
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void merge_alternate(char *src1,char *src2,char *dest)
{
    FILE *fp1,*fp2,*fp_dest;
    bool flag1=true,flag2=true,__break=1;
    fp1=fopen(src1,"r");
    fp2=fopen(src2,"r");
    fp_dest=fopen(dest,"w");
    char line[100]={0};
    if(fp1==NULL || fp2==NULL || dest==NULL){
        printf("Error in file opening\nno such file\n");
        return;
    }
    while (flag1 && flag2)
    {
        if(__break){
            if(fgets(line,100,fp1)==NULL) flag1=false;
            __break=0;
        }
        else{
            if(fgets(line,100,fp2)==NULL) flag2=false;
            __break=1;
        }
        fputs(line,fp_dest);
    }
    if(flag1){
        while (fgets(line,100,fp1)!=NULL)
            fputs(line,fp_dest);
    }    
    if(flag2){
        while (fgets(line,100,fp2)!=NULL)
            fputs(line,fp_dest);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp_dest);
    return;
}
int main(){
    char file1[32],file2[32],dest[32];
    printf("Enter file 1:");
    scanf("%s",file1);
    printf("Enter file 2:");
    scanf("%s",file2);
    printf("Enter destination file:");
    scanf("%s",dest);
    merge_alternate(file1,file2,dest);
    return 0;
}