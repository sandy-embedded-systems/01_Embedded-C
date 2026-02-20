 /*
 18.Display the lines of a file in reverse order (from last to first).
Input: File name: lines.txt
Output: Shows lines from bottom to top
*/
#include<stdio.h>
void show_lines_rev(void){
    char filename[32];
    FILE *fp;
    printf("enter file name:");
    scanf("%s",filename);
    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("No such file\n");
        return;
    }
    
}