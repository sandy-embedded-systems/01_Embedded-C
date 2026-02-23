/*
Replace every use of a chosen word in a file with a different word.
Input: File name: info.txt
Word to replace: file
Replacement: document
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceWord(char *filename){
    char oldWord[50],newWord[50];
    char word[100];
    printf("Enter word to replace: ");
    scanf("%s",oldWord);
    printf("Enter new word: ");
    scanf("%s",newWord);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL){
        printf("File not found!\n");
        return;
    }
    FILE *temp=fopen("temp.txt","w");
    if(temp==NULL){
        printf("Unable to create temp file!\n");
        fclose(fp);
        return;
    }
    while(fscanf(fp,"%s",word)!=EOF){
        if (strcmp(word,oldWord)==0)
            fprintf(temp,"%s \n",newWord);
        else
            fprintf(temp,"%s \n",word);
    }
    fclose(fp);
    fclose(temp);
    remove(filename);             
    rename("temp.txt",filename);  
    printf("Replacement completed successfully.\n");
    return;
}
int main(){
    char filename[100];

    printf("Enter file name: ");
    scanf("%s", filename);
    replaceWord(filename);
    return 0;
}