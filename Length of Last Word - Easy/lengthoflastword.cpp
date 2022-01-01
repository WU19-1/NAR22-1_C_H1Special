#include<stdio.h>
#include<string.h>

//trainee can only use strlen, nothing else, if trainee use other function
//trainee score will be 0 for this case.

int lengthOfLastWord(char *s){
	int last = 0, temp = 0, idx = 0, ln = strlen(s) - 1;
	while(true){
		if(s[ln] == ' '){
			s[ln] = '\0';
		} else break;
		ln--;
	}
	while(s[idx] != '\0'){
		if (s[idx] == ' '){
			last = temp;
			temp = 0;
		} else {
			temp++;
		}
		idx++;
	}
	if(s[idx] != ' ') last = temp;
	return last;
}

int main(){
	char arr[] = "   fly me   to   the moon  ";
//	char arr[] = "luffy is still joyboy";
//	printf("%d\n", lengthOfLastWord("Hello World"));
	printf("%d\n", lengthOfLastWord(arr));
//	printf("%d\n", lengthOfLastWord("luffy is still joyboy"));
	return 0;
}
