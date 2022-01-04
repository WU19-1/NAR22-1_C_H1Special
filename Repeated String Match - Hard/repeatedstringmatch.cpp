#include<bits/stdc++.h>

using namespace std;

void kmpPreprocess(int* preprocess, string pattern){
	int idx = 1;
	int len = 0;
	
	int stringlength = pattern.length();
	
	preprocess[0] = 0;
	while(idx < stringlength){
		if (pattern[idx] == pattern[len]){
			len++;
			preprocess[idx] = len;
			idx++;
		} else {
			if (len != 0){
				len = preprocess[len - 1];
			} else {
				preprocess[idx] = 0;
				idx++;
			}
		}
	}
}

int repeatedStringMatch(string a, string b){
	int preprocess[10001];
	kmpPreprocess(preprocess, b);
		
	int len = a.length(), plen = b.length();
	for(int i = 0, j = 0; i < len;){
		if (a[(i + j) % len] == b[j]){
			j += 1;
		}
		
		if(j == plen){
			if ((i + j) % len )
				return (i + j) / len + 1;
			return (i + j) / len;
		}
		else if(i < len && a[(i + j) % len] != b[j]) {
			if (j != 0){
				i += (j - preprocess[j-1]);
				j = preprocess[j - 1];
			}
			else 
				i++;
		}
	}
	return -1;	
}

int main(){
	string a = "", b = "";
	
	cin >> a;
	cin >> b;
	
	printf("%d\n", repeatedStringMatch(a, b));
	
	return 0;
}
