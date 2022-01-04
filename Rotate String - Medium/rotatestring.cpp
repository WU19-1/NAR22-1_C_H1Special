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

int main(){
	string s = "";
	string goal = "";
	cin >> s;
	cin >> goal;
	printf("%d\n", rotateString(s, goal));
	return 0;
}
