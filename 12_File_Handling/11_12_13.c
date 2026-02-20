/*
11. Show all the contents in a file and also print the total number of lines.
Input: File name: lines.txt
Output: (shows all lines)
Total lines: 5

12. Remove a specific line (by line number) from a file.
Input: File name: lines.txt
Line to remove: 2
Output: File now contains all lines except line 2.

13. Change a particular line in a file to some new text.
Input: File name: lines.txt
Line number: 3
New text: This line has been changed!
Output: File now contains new text at line 3.
*/

#include<stdio.h>
#include<stdlib.h>
/* Show all the contents in a file and also print the total number of lines */
void show_content(void){
    FILE *fp;
    int lines=0;
    char str[100],filename[32];
    printf("Enter file name:");
    scanf("%s",filename);
    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("No such file\n");
        return;
    }
    while(fgets(str,100,fp)!=NULL){
        lines++;
        printf("%s",str);
    }
    printf("\nTotal lines:%d\n",lines);
    fclose(fp);
    return;
}

/*Remove a specific line (by line number) from a file*/
void rem_line(void){
    FILE *fp,*temp;
    char buffer[256],filename[32];
    int line_no,current_line=1;
    printf("Enter file name:");
    scanf("%s",filename);
    printf("Enter line number to delete: ");
    scanf("%d",&line_no);
    fp=fopen(filename, "r");
    if(fp==NULL){
        printf("File not found\n");
        return;
    }
    temp=fopen("temp.txt","w");
    if(temp==NULL){
        printf("Unable to create temp file\n");
        fclose(fp);
        return;
    }
    while (fgets(buffer,sizeof(buffer),fp)) {
        if (current_line!=line_no) {
            fputs(buffer,temp);
        }
        current_line++;
    }
    fclose(fp);
    fclose(temp);
    remove(filename);
    rename("temp.txt", filename); 
    return;
}

/* Change a particular line in a file to some new text. */
void change_line_content(void){
    FILE *fp, *temp;
    char filename[32];
    char buffer[256];
    char new_text[256];
    int line_no, current_line = 1;
    int line_found = 0;
    printf("Enter file name: ");
    scanf("%s",filename);
    printf("Enter line number to modify: ");
    scanf("%d",&line_no);
    getchar();
    printf("Enter new text: ");
    fgets(new_text,sizeof(new_text),stdin);
    fp=fopen(filename, "r");
    if(fp==NULL){
        printf("File not found!\n");
        return;
    }
    temp=fopen("temp.txt","w");
    if(temp==NULL){
        printf("Unable to create temp file!\n");
        fclose(fp);
        return;
    }
    while(fgets(buffer,sizeof(buffer),fp)){
        if(current_line==line_no){
            fputs(new_text,temp);
            line_found=1;
        }
        else{
            fputs(buffer,temp);  
        }
        current_line++;
    }
    fclose(fp);
    fclose(temp);
    if(!line_found){
        printf("Line number not found!\n");
        remove("temp.txt");
        return;
    }
    remove(filename);
    rename("temp.txt",filename);
}
int main()
{
    show_content();
    rem_line();
    change_line_content();
    return 0;

}