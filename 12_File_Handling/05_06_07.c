/*
5. Add more lines to the end of a file without erasing its current content.
Input: File name: lines.txt
Number of new lines: 2
New lines: Line four, Line five
Output: File now contains: Line one, Line two, Line three, Line four, Line five

6. Copy everything from one file and save it into another file.
Input: Source file: lines.txt
Destination file: copy.txt
Output: File 'lines.txt' copied to 'copy.txt'.

7. Delete a file from the computer.
Input: File name: temp.txt
Output: File 'temp.txt' deleted.
*/

#include<stdio.h>
/* Add more lines to the end of a file without erasing its current content */
void append_file(void){
    FILE *fp;
    char str[100];
    fp=fopen("lines.log","a");
    if(fp==NULL){
        printf("No such file\n");
        return;
    }
    printf("enter content:");
    scanf("%s",str);
    fputs(str,fp);
    fclose(fp);
}
/* Copy everything from one file and save it into another file*/
void copy(void){
    FILE *f_src,*f_dst;
    f_src=fopen("lines.log","r");
    f_dst=fopen("copy.txt","w");
    char ch;
    while((ch=fgetc(f_src))!=EOF)
        fputc(ch,f_dst);
}
/*Delete a file from the computer.*/
void delete_file(){
    char filename[30];
    printf("Enter file name:");
    scanf("%s",filename);
    if(remove(filename)){
        printf("No such file in exist\n");
        return;
    }
    else printf("file '%s' is deleted\n",filename);
}
int main(){
    append_file();
    copy();
    delete_file();
    return 0;
}