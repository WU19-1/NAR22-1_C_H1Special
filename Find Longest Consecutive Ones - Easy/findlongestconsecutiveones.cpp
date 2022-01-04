#include<stdio.h>

int main(){
	
	int n = 0;
	char c = '\0';
	int max = 0, temp = 0;
	
	scanf("%d\n", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%c", &c);
		if (c == '1'){
			temp++;
		} else if (c == '0'){
			if(temp > max){
				max = temp;
			}
			temp = 0;
		}
	}
	if (temp > max){
		max = temp;
	}
	printf("%d\n", max);
	
	return 0;
}
