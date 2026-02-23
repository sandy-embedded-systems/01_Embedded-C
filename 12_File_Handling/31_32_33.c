/*
31. Add up numbers given as command line arguments and write the answer into a file.
Input: Arguments: 3 4 5, Output file: sum.txt
Output: sum.txt contains: 12

32. Count how many lines in a file end with a semicolon.
Input: File: data.txt (lines, some end with ;)
Output: Lines ending with semicolon: 2

33. Count how many empty (blank) lines are in a file.
Input: File: data.txt
Output: Blank lines: 1
*/ 

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/* Count how many empty (blank) lines are in a file. */
void cntEmpty_Blanks(void){
    char filename[32];
    FILE *fp;
    char str[100]={0};
    int blanks=0;
    printf("enter file name:");
    scanf("%s",filename);
    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("No such file\n");
        return;
    }
    while (fgets(str,100,fp)!=NULL)
    {
        if(str[0]=='\n') blanks++;
    }
    printf("Blank Lines: %d\n",blanks);
    fclose(fp);
    return;    
}

/* Count how many lines in a file end with a semicolon */
void cntLines_with_semis(void){
        char filename[32];
    FILE *fp;
    char str[100]={0};
    int lines=0;
    printf("enter file name:");
    scanf("%s",filename);
    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("No such file\n");
        return;
    }
    while (fgets(str,100,fp)!=NULL)
    {
        if(str[strlen(str)-2]==';') lines++;
    }
    printf("Lines ending with semi-colon:%d\n",lines);
    fclose(fp);
    return;
}

/*  Add up numbers given as command line arguments and write the answer into a file */
int check_str(const char *s){
    for(int i=0;s[i];i++){
        if(!isdigit(s[i])) return 0;
    }
    return 1;
}
void addCmcArgs(int argc,char **argv){
    if(argc==1) return;
    FILE* fp;
    fp=fopen("result.txt","w");
    int result=0;
    for(int i=1;i<argc;i++){
        if(check_str(argv[i])) result+=atoi(argv[i]);
    }
    fprintf(fp,"%d",result);
    fclose(fp);
}
int main(int argc,char *argv[]){
    addCmcArgs(argc,argv);
    cntEmpty_Blanks();
    cntLines_with_semis();
    return 0;
}