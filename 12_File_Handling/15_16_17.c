/*
15. Change all the letters in a file to uppercase.
Input: File name: info.txt (content: Hello World!)
Output: HELLO WORLD!

16. Change all the letters in a file to lowercase.
Input: File name: info.txt (content: Hello World!)
Output: hello world!

17. Capitalize the first letter of each word in a file.
Input: File name: info.txt (content: hello world!)
Output: Hello World!
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/* Change all the letters in a file to uppercase. */
void change_to_upper(void){
    char filename[32],*data=NULL;
    FILE *fp;
    int len;
    printf("enter file name:");
    scanf("%s",filename);
    fp=fopen(filename,"r");
    fseek(fp,0,SEEK_END);
    len=ftell(fp);
    rewind(fp);
    data=calloc(1,len+1);
    fread(data,1,len,fp);
    fclose(fp);
    for(int i=0;i<len;i++)
        if(islower(data[i])) data[i]^=32;
    fp=fopen(filename,"w");
    fwrite(data,1,len,fp);
    fclose(fp);
    return;
}

/* Change all the letters in a file to lowercase. */
void change_to_lower(void){
    char filename[32],*data=NULL;
    FILE *fp;
    int len;
    printf("enter file name:");
    scanf("%s",filename);
    fp=fopen(filename,"r");
    fseek(fp,0,SEEK_END);
    len=ftell(fp);
    rewind(fp);
    data=calloc(1,len+1);
    fread(data,1,len,fp);
    fclose(fp);
    for(int i=0;i<len;i++)
        if(isupper(data[i])) data[i]^=32;
    fp=fopen(filename,"w");
    fwrite(data,1,len,fp);
    fclose(fp);
    return;
}

/*Capitalize the first letter of each word in a file.*/
void capitalize_each_word(void){
    char ch,filename[32],*buff;
    FILE *fp;
    int new_word=1;
    printf("Enter file name:");
    scanf("%s",filename);
    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("File not found\n");
        return;
    }
    fseek(fp,0,SEEK_END);
    int len=ftell(fp);
    rewind(fp);
    buff=calloc(1,len);
    fread(buff,1,len,fp);
    fclose(fp);
    for(int i=0;i<len;i++){
        if(new_word && islower(buff[i])){       
            buff[i]^=32; 
            new_word=0;
        }
        else if(isspace(ch)){
            new_word=1;
        }
        else{
            new_word = 0;
        }
    }
    fp=fopen(filename,"w");
    fwrite(buff,1,len,fp);
    free(buff);
    fclose(fp);
}
int main(){
    change_to_upper();
    change_to_lower();
    capitalize_each_word();
    return 0;
}