#include<bits/stdc++.h>

using namespace std;
int counter = 0;
void decode(string s, int idx, int len, int previousNumber){
    if(idx == len){
        if (previousNumber == 0)
            counter += 1;
        return;
    }
//	cout << previousNumber + s[idx] - 48 << endl;
    if(s[idx] - 48 == 1 && previousNumber == 0){
//		cout << "masuk pertama" << endl;
        decode(s, idx + 1, len, 10);
    } 
    if(s[idx] - 48 == 2){
//		cout << "masuk kedua" << endl;
        if(s[idx + 1] - 48 <= 6 && previousNumber == 0){
//			cout << "masuk lagi" << endl;
            decode(s, idx + 1, len, 20);
        }
    }
    if(s[idx] - 48 != 0 || (s[idx] - 48 == 0 && previousNumber != 0))
        decode(s, idx + 1, len, 0);
}

int numDecodings(string s) {
    if (s[0] == '0') return 0;
    counter = 0;
    decode(s, 0, s.length(), 0);
    return counter;
}

int main(){
//	string s = "226";
//	string s = "06";
//	string s = "12";
	string s = "11106";
	cout << numDecodings(s) << endl;
	return 0;
}
