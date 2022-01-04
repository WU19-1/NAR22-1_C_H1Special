#include<bits/stdc++.h>

using namespace std;

string simplifyPath(string path) {
    vector<string> changed_path;
    vector<string> filtered_path;
    
    string full_path = "/";
    int count = 0;
    
    //splitting string first
    int current = 0, previous = 0;
    current = path.find("/");
    while(current != string::npos){
        changed_path.push_back(path.substr(previous, current - previous));
        previous = current + 1;
        current = path.find("/", previous);
    }
    changed_path.push_back(path.substr(previous, current - previous));
    
    
    for(int i = 0; i < changed_path.size(); i++){
        if(changed_path[i] == "." || changed_path[i] == "" || changed_path[i] == " ") continue;
        else {
            if(changed_path[i] == ".." && count == 0) continue;
            else if(changed_path[i] == ".." && count != 0){
            	count -= 1;
            	filtered_path.pop_back();
			}
            else {
                filtered_path.push_back(changed_path[i]);
                count += 1;
            }
        }
    }
    for(int i = 0; i < filtered_path.size(); i++){
        full_path += filtered_path[i];
        if (i != filtered_path.size() - 1)
            full_path += "/";
    }
    
    return full_path;
}

int main(){
	string path = "";
	cin >> path;
	cout << simplifyPath(path);
	return 0;
}
