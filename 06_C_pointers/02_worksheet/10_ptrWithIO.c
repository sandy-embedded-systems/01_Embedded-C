/*
10. Pointer and File I/O
Goal: Use pointers and dynamic memory to efficiently read and write data of variable sizes to files.

Activity:

Open a file for reading and writing.
Determine the size of the file or data to read.
Dynamically allocate a buffer to hold file data.
Use pointers to read the data into memory and write data back to a file.
Close the file and free allocated memory.
*/

#include<stdio.h>
#include<stdlib.h>
unsigned int sizeOfFile(FILE *fp)
{
	unsigned int size=0;
	fseek(fp,0,SEEK_END);
	size=ftell(fp);
	rewind(fp);
	return size;
}
void fileIO(FILE *fp)
{
	unsigned int size=sizeOfFile(fp);
	char *buffer=(char*)calloc(1,size+1);
	fread(buffer,1,size,fp);
	printf("File data stored to dynamic memory\n");
	fwrite(buffer,1,size,fp);
	free(buffer);
}
int main(int argc,char *argv[])
{
	if(argc!=2){
		printf("ERROR: Invalid arguments\ninput typo:$ ./a.out <file_name>\n");
		return 0;
	}
	FILE *fp=NULL;
	fp=fopen(argv[1],"r+");
	if(fp==NULL){
		printf("%s:No such file\n",argv[1]);
		return 0;
	}
	sizeOfFile(fp);
	fileIO(fp);
	fclose(fp);
}
