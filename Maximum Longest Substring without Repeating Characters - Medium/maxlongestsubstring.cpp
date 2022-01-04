#include<bits/stdc++.h>

using namespace std;

bool arr[256];

int lengthOfLongestSubstring(string s) {
    memset(arr, 0, sizeof(arr));
    if (s.length() == 0) return 0;
    if (s.length() == 1) return 1;
    
    int left = 0, right = 1, max = 0, len = 1;
    
    arr[s[0]] = true;
    
    while(right <= s.length() - 1){
        if (arr[s[right]] == false){
            arr[s[right]] = true;
            len += 1;
            right += 1;
            if(len > max){
                max = len;
            }
        } else {
            arr[s[left]] = false;
            len -= 1;
            left += 1;
        }
    }
    
    return max;
}

int main(){
	string s = "";
	cin >> s;
	cout << lengthOfLongestSubstring(s) << endl;
	return 0;
}
