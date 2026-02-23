/*
25. List all the files found inside a directory (folder).
Input: Directory: myfolder/
Output: file1.txt, file2.txt, notes.doc

26. Find out how big a file is (in bytes).
Input: File name: a.txt
Output: Size: 36 bytes
*/

#include<stdio.h>
#include<dirent.h>
#include<string.h>

/* Find out how big a file is (in bytes) */
void sizeof_file(char *filename){
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("No such file :%s\n\n",filename);
        return;
    }
    fseek(fp,0,SEEK_END);
    printf("size :%d bytes\n\n",ftell(fp));
    rewind(fp);
    fclose(fp);
    return;
}

/* List all the files found inside a directory */
void list_of_files(void){
    DIR *dir;
    struct dirent *entry;
    dir=opendir(".");
    if(dir==NULL){
        perror("opendir");
        return;
    }
    printf("Files in directory:\n");
    while ((entry=readdir(dir))!=NULL) {
        printf("%s\n",entry->d_name);
    }
    closedir(dir);
}
int main(){
    char name[32];
    printf("Enter file name:");
    scanf("%s",name);
    sizeof_file(name);
    list_of_files();
    return 0;
}