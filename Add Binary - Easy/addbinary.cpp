#include<bits/stdc++.h>

using namespace std;

string result = "";

void rec(string a, int ai, string b, int bi, bool ex){
    char temp_a = '0';
    char temp_b = '0';
    if (ai < 0 && bi < 0){
        if (ex)
            result = "1" + result;
        return;
    }
    if (ai >= 0)
        temp_a = a[ai];
    if (bi >= 0)
        temp_b = b[bi];
    
    if (temp_a == temp_b && temp_a == '1'){
        result = ((ex) ? '1' : '0') + result;
        ex = true;
    } else if (temp_a == temp_b && temp_a == '0'){
        result = ((ex) ? '1' : '0') + result;
        ex = false;
    } else {
        if (ex){
            result = '0' + result;
            ex = true;
        } else {
            result = '1' + result;
            ex = false;
        }
    }
    rec(a, ai - 1, b, bi - 1, ex);
}

string addBinary(string a, string b) {
    result = "";
    rec(a, a.length() - 1, b, b.length() - 1, false);
    return result;
}

int main(){
	
	return 0;
}
