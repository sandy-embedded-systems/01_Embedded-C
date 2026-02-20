
/*
7. Remove from the first string all characters that appear in the second string.
Input: str1 = "hello world", str2 = "low"
Output: "he rd"

8. Check if one string is a rotation of another, i.e., one string can be shifted to get the other.
Input: "abcd", "cdab"
Output: Yes
*/

#include<stdio.h>
#include<string.h>
/* Check if one string is a rotation of another */
void checkRotation(char *str1,char *str2){
	char flag=1,ch,len=strlen(str1);
	for(int i=0;str1[i];i++){
		if(strcmp(str1,str2)==0){
			printf("Yes \n");
			flag=0;
			break;
		}
		else{
			ch=str1[i];
			memmove(str1+i,str1+i+1,strlen(str1+i+1));
			str1[len-1]=ch;
		}
	}
	if(flag) printf("No\n\n");
}

/* Remove from the first string all characters that appear in the second string */
void remChars(char *str1,char *str2)
{
	for(int i=0;str2[i];i++){
		for(int j=0;str1[j];j++){
			if(str1[j]==str2[i])
				for(int k=j;str1[k];k++)
					str1[k]=str1[k+1];
		}
	}
	printf("%s\n",str1);
}

int main(){
	char str1[50],str2[20],ch;
	printf("Enter string 1:");
	scanf("%[^\n]s",str1);
	while((ch=getchar())!='\n');
	printf("Enter string 2:");
	scanf("%s",str2);
	/*if(strlen(str1)!=strlen(str2)){
		printf("No\n");
		return 0;
	}*/
	checkRotation(str1,str2);
	remChars(str1,str2);
}
