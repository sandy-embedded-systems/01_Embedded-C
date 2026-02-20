
/*
1. Make a new file and save some text entered by the user.
Input: File name: test.txt
Text: Hello, this is my first file!
Output: File 'test.txt' created and saved.

2. Open an existing file and display its contents on the screen.
Input: File name: test.txt
Output: Hello, this is my first file!

3. Take several lines from the user and write all of them into a file.
Input: File name: lines.txt
Number of lines: 3
Lines: Line one, Line two, Line three
Output: All lines saved in 'lines.txt'.

4. Read every line from a file and store those lines in an array.
Input: File name: lines.txt
Output: Line one, Line two, Line three (as array elements)
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* save some text entered by the user to test.txt file */
void save_text(void){
    char str[100],ch;
    printf("Enter file content:");
    scanf("%[^\n]",str);
    FILE *fp=NULL;
    fp=fopen("test.txt","w+");
    fwrite(str,1,strlen(str),fp);
    fclose(fp);
    return;
}

/*Open an existing file and display its contents on the screen.*/
void view_file(void){
    FILE *fp=NULL;
    char text[100];
    fp=fopen("test.txt","r");
    if(fp==NULL){
        printf("No such file \n");
        return;
    }
    fread(text,99,1,fp);
    printf("%s\n",text);
    fclose(fp);
    return;
}

/* Take several lines from the user and write all of them into a file. */
void save_lines(void){
    int lines;
    char str[100];
    FILE *fp=fopen("lines.log","w");
    if(fp==NULL){
        printf("File open failed\n");
        return;
    }
    printf("Enter how many lines you should enter:");
    scanf("%d",&lines);
    getchar();
    for(int i=0;i<lines;i++){
        scanf("%s",str);
        fprintf(fp,"%s\n",str);
    }
    fclose(fp);
}
/*Read every line from a file and store those lines in an array.*/
void view_lines(void){
    FILE *fp;
    int i=0;
    char *lines[20]={0},buffer[100];
    fp=fopen("lines.log","r");
    if(fp==NULL){
        printf("File open failed\n");
        return;
    }
    while(fgets(buffer,sizeof(buffer),fp)!=NULL)
    {
        lines[i]=calloc(1,100);
        strcpy(lines[i],buffer);
        printf("%s", buffer);
        i++;
    }
    i--;
    while (i>=0)
        free(lines[i--]);
    return;
}
int main(){
    save_text();
    view_file();
    save_lines();
    view_lines();
    return 0;
}