#include<bits/stdc++.h>

using namespace std;

int deepest = 0;

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

int inorder(vector<int>& root, int idx, int level){
	int left = getLeft(root, idx);
	int right = getRight(root, idx);
    if(root[right] != 0 || root[left] != 0){
        int res = 0;
        if(root[left] != 0){
            res += inorder(root, left, level + 1);
        }
        if(root[right] != 0){
            res += inorder(root, right, level + 1);
        }
        return res;
    } else {
        if (level == deepest && root[idx] != 0){
            return root[idx];
        }
        return 0;
    }
}

void find(vector<int>& root, int idx, int level){
    if(root[idx] != 0){
        if(level > deepest)
            deepest = level;
        find(root, getLeft(root, idx), level + 1);
        find(root, getRight(root, idx), level + 1);
    }
}

int deepestLeavesSum(vector<int>& root) {
    find(root, 1, 0);
    return inorder(root, 1, 0);
}

int main(){
	vector<int> root(101, 0);
	int n = 0, temp = 0;;
	
	cin >> n;
	for(int i = 1 ; i <= n; i++){
		cin >> temp;
		root[i] = temp;
	}
	
	cout << deepestLeavesSum(root) << endl;
	
	return 0;
}
