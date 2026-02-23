/*
Group a list of words so that anagrams are together.
I put: ["cat", "tac", "act", "dog"]
Output: ["cat", "tac", "act"], ["dog"]

Count the number of words in a string separated by spaces.
 nput: "Hello world"
Output: 2
*/

#include<stdio.h>
#include<string.h>
#define MAX 100
#define WORD_LEN 20
void sortWord(char *word,char *sorted){
    strcpy(sorted,word);
    int len=strlen(sorted);
    char temp;
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(sorted[i]>sorted[j]){
                temp=sorted[i];
                sorted[i]=sorted[j];
                sorted[j]=temp;
            }
        }
    }
}
int isAnagram(char *w1,char *w2){
    char s1[WORD_LEN],s2[WORD_LEN];
    sortWord(w1,s1);
    sortWord(w2,s2);
    return strcmp(s1, s2)==0;
}

// Function to group anagrams
void groupAnagrams(char words[][WORD_LEN],int n){
    int visited[MAX]={0};
    for(int i=0;i<n;i++){
        if(visited[i])
            continue;
        printf("[ %s",words[i]);
        visited[i]=1;
        for(int j=i+1;j<n;j++){
            if(!visited[j] && isAnagram(words[i],words[j])){
                printf(", %s",words[j]);
                visited[j]=1;
            }
        }
        printf(" ]\n");
    }
}

/* Count the number of words in a string separated by spaces */
int countWords(char *str){
    int count=0;
    int i=0;
    while(str[i]){
        if(str[i]!=' ' &&(i==0 ||str[i-1]==' '))
        {
            count++;
        }
        i++;
    }
    return count;
}
int main(){
    char str[40];
    char *words[WORD_LEN];
    int n=0;
    printf("enter no.of words:");
    scanf("%d",&n);
    if(n<=0){
        printf("Invalid input\n\n");
        return 0;
    }
    for(int i=0;i<n;i++){
        words[i]=calloc(1,30);
        printf("enter word %d:",i+1);
        scanf("%s",words[i]);
    }
    groupAnagrams(words,n);
    printf("enter string:");
    scanf("%[^\n]",str);
    printf("No.of words: %d\n\b",countWords(str));
}