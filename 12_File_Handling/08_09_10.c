/*
8. Read a value from a file into a variable, and also write a variable’s value back into a file.
Input: File name: number.txt (contains: 42)
Output: Read variable: 42; After writing value 100, file now contains: 100

9. Count how many lines are present in a text file.
Input: File name: lines.txt
Output: Total lines: 5

10. Count both the number of words and the number of characters in a file.
Input: File name: info.txt (content: This is a test file.)
Output: Words: 5
Characters: 21
*/

#include<stdio.h>
/*Read a value from a file into a variable*/
void read_value(void){
    FILE *fp;
    int val;
    fp=fopen("number.txt","r+");
    if(fp==NULL){
        printf("No such file\n");
        return;
    }
    fscanf(fp,"%d",&val);
    printf("value from file:%d\n",val);
    val=100;
    rewind(fp);
    fprintf(fp,"%d",val);
    fclose(fp);
}

/* count how many lines are present in a text file.*/
void count_lines(void){
    int lines=0;
    FILE *fp;
    char str[100];
    fp=fopen("lines.log","r");
    if(fp==NULL){
        printf("No such file\n");
        return;
    }
    while(fgets(str,100,fp)!=NULL)
        lines++;
    printf("Total Lines: %d\n",lines);
}

/* Count both the number of words and the number of characters in a file */
void cnt_words_chars(void){
    int words=0,chars=0;
    FILE *fp;
    char ch;
    fp=fopen("lines.log","r");
    if(fp==NULL){
        perror("fopen");
        return;
    }
    while((ch=fgetc(fp))!=EOF){
        if(ch==' ' || ch=='\n') words++;
        else chars++;
    }
    printf("Words: %d\ncharacters:%d\n",words+1,chars);
}
int main(){
    read_value();
    count_lines();
    cnt_words_chars();
    return 0;
}