#include<stdio.h>

int main(){
	
	FILE* fp = fopen("testdata.in", "r");
	
	int n = 0;
	char c = '\0';
	int max = 0, temp = 0;
	
	fscanf(fp, "%d\n", &n);
	
	for(int i = 0; i < n; i++){
		fscanf(fp, "%c", &c);
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
