#include<stdio.h>
#include<string.h>
/* remove duplicates from the string */
void removeDuplicates(char *str)
{
    unsigned char seen[256]={0};
    int i,j=0;
    for(i=0;str[i];i++)
    {
        if(!seen[(unsigned char)str[i]])
        {
            seen[(unsigned char)str[i]]=1;
            str[j++]=str[i];
        }
    }
    str[j] = '\0';
    printf("%s\n",str);
}

/* print characters that occur more than once */
void charsOccured(char *str)
{
	int cnt;
	char temp[27]={0},k=0;
	for(int i=0;str[i];i++){
		if(strchr(temp,str[i])) continue;
		cnt=0;
		for(int j=0;str[j] && cnt<2;j++){
			if(str[i]==str[j]) cnt++;
		}
		if(cnt>=2) temp[k++]=str[i];
	}
	for(int i=0;i<k;i++){
		printf("%c ",temp[i]);
	}
	printf("\n\n");
}

int main(){
        char str[50];
        printf("Enter string:");
        scanf("%[^\n]s",str);
	charsOccured(str);
	removeDuplicates(str);
        return 0;
}
