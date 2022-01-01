#include<stdio.h>
#include<string.h>

int isPrefixOfWord(char * sentence, char * searchWord){
    char* ref = strtok(sentence, " ");
    int i = 1, j = 0, searchLen = strlen(searchWord), wordLen = 0;
    while(ref != NULL){
//    	puts(ref);
    	wordLen = strlen(ref);
    	if (wordLen >= searchLen){
    		j = 0;
    		while (j < searchLen){
//    			printf("%c %c\n", ref[j], searchWord[j]);
    			if (ref[j] != searchWord[j]){
    				break;
				}
    			++j;
			}
			if (j == searchLen)
				return i;
		}
		++i;
		ref = strtok(NULL, " ");
	}
	return -1;
}

int main(){
	char sentence[] = "i love eating burger", searchWord[] = "burg";
	printf("%d\n", isPrefixOfWord(sentence, searchWord));
	return 0;
}
