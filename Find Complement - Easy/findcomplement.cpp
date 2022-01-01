#include<stdio.h>
#include<string.h>

int findComplement(int num){
	int ln = 0;
	char arr[100] = "";
	int temp = 0;
	while(num != 0){
		temp = num % 2;
		if (temp == 0){
			strcat(arr, "1");
		} else {
			strcat(arr, "0");			
		}
		num /= 2;
		ln++;
	}
	temp = 0;
	int base = 1;
	for (int i = 0; i < ln; i++){
		if(arr[i] == '1'){
			temp += base;
		}
		base *= 2;
	}
	return temp;
}

int main(){
	printf("%d\n", findComplement(5));
	printf("%d\n", findComplement(7));
	printf("%d\n", findComplement(10));
	
	return 0;
}
