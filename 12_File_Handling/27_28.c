/*
27. Show the last modification date and time of a file.
Input: File name: a.txt
Output: Last modified: Sat Nov 26 17:32:15 2022

28. Find the common folder path among a group of file paths.
Input: /home/user/docs/a.txt, /home/user/docs/b.txt, /home/user/docs/old/c.txt
Output: /home/user/docs
*/
#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<string.h>

/* Last modification data and time of file */
void last_modified(char * file){
    struct stat file_stat;
    if (stat(file, &file_stat) == -1) {
        perror("stat");
        return;
    }
    printf("Last modified: %s", ctime(&file_stat.st_mtime));
    return;
}

/* the common folder path among a group of file paths */
void common_paths(int argc,char **paths){
    char common[256];
    strcpy(common, paths[0]);
    for(int i=2;i<argc;i++){
        int j=0;
        while(common[j] &&paths[i][j] && 
               common[j]==paths[i][j]){
            j++;
        }
        common[j]='\0';
    }
    char *last_slash=strrchr(common,'/');
    if(last_slash!=NULL){
        *last_slash='\0';
    }
    printf("Common folder path: %s\n",common);
}
int main(int argc,char *argv[]){
    if(argc==1){
        printf("ERROR: input format failed\n.exe paths ...\n\n");
        return 0;
    }
    char file[32];
    printf("Enter file name to find last modification time:");
    scanf("%s",file);
    last_modified(file);
    common_paths(argc,argv);
    return 0;
}