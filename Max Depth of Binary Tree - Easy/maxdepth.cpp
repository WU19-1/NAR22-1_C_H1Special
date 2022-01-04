#include<bits/stdc++.h>

using namespace std;

int maxx = 0;

int getLeft(vector<int>& root, int idx){
	idx = idx * 2;
	if (idx > root.size()) return 0;
	return idx;
}

int getRight(vector<int>& root, int idx){
	idx = (idx * 2) + 1;
	if (idx > root.size()) return 0;
	return idx; 
}

void find(vector<int>& root, int idx, int level){
    if(root[idx] != 0){
        if(level > maxx)
            maxx = level;
        find(root, getLeft(root, idx), level + 1);
        find(root, getRight(root, idx), level + 1);
    }
}

int maxDepth(vector<int> root) {
    maxx = 0;
    find(root, 1, 1);
    return maxx;
}

int main(){
	vector<int> root(10001, 0);
	
	int n = 0, temp = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> temp;
		root[i] = temp;
	}
	
	cout << maxDepth(root) << endl;
	
	return 0;
}
