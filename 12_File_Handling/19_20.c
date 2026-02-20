/*
19. Encrypt (scramble) a file’s content so it can’t be read easily.
Input: File name: secret.txt (content: my password)
Output: File now contains: (garbled/encrypted text)

20. Decrypt a scrambled (encrypted) file and make it readable again.
Input: File name: secret.txt (content: encrypted)
Output: File now contains: my password
*/

#include<stdio.h>
 /* encrypt a file's content */
 void encrypt_file()
{
    char filename[100];
    char ch;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
    printf("file not found\n");
    return;
    }
    FILE *ft=fopen("temp.txt","w");
    while((ch=fgetc(fp))!=EOF)
    {
    fputc(ch+3,ft);
    }
    fclose(fp);
    fclose(ft);
    remove(filename);
    rename("temp.txt",filename);
    printf("file encrypted\n");
}

/* decrypt a file content */
void decrypt_file()
{
    char filename[100];
    char ch;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
    printf("file not found\n");
    return;
    }
    FILE *ft=fopen("temp.txt","w");
    while((ch=fgetc(fp))!=EOF)
    {
    fputc(ch-3,ft);
    }
    fclose(fp);
    fclose(ft);
    remove(filename);
    rename("temp.txt",filename);
    printf("file decrypted\n");
}

int main(){
    encrypt_file();
    decrypt_file();
    return 0;
}
