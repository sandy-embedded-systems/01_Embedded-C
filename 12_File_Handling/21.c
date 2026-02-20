/*
21. Join two files together and save the result in a new file.
Input: File 1: a.txt (AAA)
File 2: b.txt (BBB)
New file: ab.txt
Output: ab.txt content: AAA
BBB

*/

#include<stdio.h>
void join_files()
{
    char f1[100],f2[100],newfile[100];
    char ch;
    printf("file 1: ");
    scanf("%s",f1);
    printf("file 2: ");
    scanf("%s",f2);
    printf("new file: ");
    scanf("%s",newfile);
    FILE *f1=fopen(f1,"r");
    FILE *f2=fopen(f2,"r");
    FILE *fn=fopen(newfile,"w");
    if(f1==NULL||f2==NULL||fn==NULL)
    {
    printf("file error\n");
    return;
    }
    while((ch=fgetc(f1))!=EOF)
    fputc(ch,fn);
    fputc('\n',fn);
    while((ch=fgetc(f2))!=EOF)
    fputc(ch,fn);
    fclose(f1);
    fclose(f2);
    fclose(fn);
    printf("files joined into '%s'\n",newfile);
}
int main(){
    join_files();
    return 0;
}
