#include<bits/stdc++.h>

using namespace std;

int memo[101];

int decode(string s, int idx){
	if(memo[idx] > -1) return memo[idx];
	if(s[idx] == '0') return memo[idx] = 0;
	int res = decode(s, idx + 1);
	
	if(idx < s.length() - 1 && (s[idx] == '1' || s[idx] == '2' && s[idx + 1] <= '6')){
		res += decode(s, idx + 2);
	}
	
	return memo[idx] = res;
}

int numDecodings(string s) {
    if (s[0] == '0') return 0;
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < s.length(); i++)
    	cout << memo[i] << endl;
    memo[s.length()] = 1;
    return decode(s, 0);
}

int main(){
//	string s = "226";
//	string s = "06";
//	string s = "12";
	string s = "11106";
	cout << numDecodings(s) << endl;
	return 0;
}
