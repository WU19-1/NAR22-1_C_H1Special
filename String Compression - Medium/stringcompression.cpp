#include<bits/stdc++.h>

using namespace std;

int compress(vector<char>& chars) {
    int first = 0, second = 0, new_len = 0, len = chars.size(), current_count = 0;
    char last_character = chars[0];
    chars.push_back('\0');
    string counter = "";
    
//    if (len == 1) return 1;
    
    for(first, second; second <= len; second++){
        if(last_character != chars[second]){
            chars[first++] = last_character;
            new_len += 1;
            counter = to_string(current_count);
            if(current_count > 1){
                for(int i = 0; i < counter.length(); i++, first++, new_len++)
                    chars[first] = counter[i];
            }
            current_count = 1;
            last_character = chars[second];
        } else {
            current_count += 1;
        }
        chars[second] = '\0';
    }
    
    return new_len;
}

int main(){
	vector<char> chars = {};
	int n = 0;
	char c = '\0';
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> c;
		chars.push_back(c);
	}
	cout << compress(chars) << endl;
	
	return 0;
}
