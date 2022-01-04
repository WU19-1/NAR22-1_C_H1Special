#include<bits/stdc++.h>

using namespace std;

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
	int n = 0, num = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> num;
		cout << "Case " << i << ": " << findComplement(num) << endl;
	}
	
	return 0;
}
