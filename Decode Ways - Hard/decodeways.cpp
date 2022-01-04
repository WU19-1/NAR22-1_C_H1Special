#include<bits/stdc++.h>

using namespace std;

int memo[201];

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
    memo[s.length()] = 1;
    return decode(s, 0);
}

int main(){
	string s = "";
	cin >> s;
	cout << numDecodings(s) << endl;
	return 0;
}
