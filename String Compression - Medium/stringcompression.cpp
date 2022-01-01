#include<bits/stdc++.h>

using namespace std;

int compress(vector<char>& chars) {
    int first = 0, second = 0, new_len = 0, len = chars.size(), current_count = 0;
    char last_character = chars[0];
    chars.push_back('\0');
    string counter = "";
    
//    if (len == 1) return 1;
    
    for(first, second; second <= len; second++){
    	cout << chars[second] << endl;
        if(last_character != chars[second]){
        	cout << "masuk pertama" << endl;
            chars[first++] = last_character;
            new_len += 1;
            counter = to_string(current_count);
            cout << "counter : " << counter << endl;
            if(current_count > 1){
            	cout << "enter the condition" << endl;
                for(int i = 0; i < counter.length(); i++, first++, new_len++)
                    chars[first] = counter[i];
            }
            current_count = 1;
            last_character = chars[second];
        } else {
        	cout << "masuk kedua" << endl;
            current_count += 1;
        }
        chars[second] = '\0';
    }
    
    return new_len;
}

int main(){
//	vector<char> chars = {'a','a','b','b','c','c','c'};
	vector<char> chars = {'a', 'a'};
//	vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
//	vector<char> chars = {'a', 'a', 'a', 'b', 'b', 'a', 'a'};
	cout << endl << compress(chars) << endl;
	for(int i = 0; i < chars.size(); i++){
		cout << chars[i];
	}
	cout << endl;
	return 0;
}
