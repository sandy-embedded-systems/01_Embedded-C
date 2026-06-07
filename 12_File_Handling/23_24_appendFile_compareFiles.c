/*
23. Take everything from one file and append it to the end of another file.
Input: File1: main.txt (Main)
File2: extra.txt (Extra)
Output: main.txt now contains: Main, Extra

24. Check if two files are exactly the same or not.
Input: File1: a.txt, File2: b.txt
Output: Files are identical or Files are different
*/

#include<stdio.h>
#include<stdlib.h>
/* append it to the end of another file. */
void append_file()
{
    char file1[100],file2[100];
    char ch;
    printf("file1: ");
    scanf("%s",file1);
    printf("file2: ");
    scanf("%s",file2);
    FILE *f1=fopen(file1,"a");
    FILE *f2=fopen(file2,"r");
    if(f1==NULL||f2==NULL)
    {
    printf("file error\n");
    return;
    }
    while((ch=fgetc(f2))!=EOF)
    fputc(ch,f1);
    fclose(f1);
    fclose(f2);
    printf("content appended successfully\n");
}

/* Check if two files are exactly the same or not */
void compare_files()
{
    char file1[100],file2[100];
    char ch1,ch2;
    int same=1;
    printf("file1: ");
    scanf("%s",file1);
    printf("file2: ");
    scanf("%s",file2);
    FILE *f1=fopen(file1,"r");
    FILE *f2=fopen(file2,"r");
    if(f1==NULL||f2==NULL)
    {
    printf("file error\n");
    return;
    }
    while(1)
    {
    ch1=fgetc(f1);
    ch2=fgetc(f2);
    if(ch1!=ch2)
    {
    same=0;
    break;
    }
    if(ch1==EOF||ch2==EOF)
    break;
    }
    fclose(f1);
    fclose(f2);
    if(same&&ch1==ch2)
    printf("files are identical\n");
    else
    printf("files are different\n");
}
int main(){
    append_file();
    compare_files();
    return 0;
}
