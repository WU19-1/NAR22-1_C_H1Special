#include<bits/stdc++.h>

using namespace std;

bool rotateString(string s, string goal) {
    int slen = s.length();
    int goalLen = s.length();
    if (goalLen < slen) return false;
    bool pre = false;
    string a = s + s;
    cout << a << endl;
    for(int i = 0, j = 0; j < goalLen;){
    	cout << goal[j];
    	if(i >= a.length() && j < goalLen) return false;
    	if(a[i] != goal[j] && !pre){
    		i++;
		}
    	else if(a[i] != goal[j] && pre){
    		pre = false;
    		j = 0;
		}
    	else if(a[i] == goal[j]){
    		pre = true;
    		j++;
    		i++;
		}
	}
	return true;
}

//bool rotateString(char * s, char * goal){
//	int len = strlen(goal);
//	int slen = strlen(s);
//	if (len < slen) return false;
//	bool pre = false;
//	
//	for(int i = 0, j = 0; j < len; i++){
//		if(i >= slen * 2 && j == 0) return false;
//		if(s[i % slen] != goal[j] && !pre) continue;
//		else if(s[i % slen] != goal[j] && pre) return false;
//		else if(s[i % slen] == goal[j]){
//			pre = true;
//			j++;
//		}
//	}
//	return true;
//}

int main(){
//	char s[] = "abcde", goal[] = "cdeab";
//	char s[] = "abcde", goal[] = "abced";
//	char s[] = "ohbrwzxvxe";
//	char goal[] = "uornhegseo";
//	string s = "bbbacddceeb";
//	string goal = "ceebbbbacdd";
	string s = "vcuszhlbtpmksjleuchmjffufrwpiddgyynfujnqblngzoogzg";
	string goal = "fufrwpiddgyynfujnqblngzoogzgvcuszhlbtpmksjleuchmjf";
	printf("\n%d\n", rotateString(s, goal));
	return 0;
}
