#include<bits/stdc++.h>

using namespace std;

vector< vector<int> > solution;

bool check(vector<int> temp){
    bool test = true;
    for(int i = 0; i < solution.size(); i++){
        if(temp.size() != solution[i].size()) continue;
        test = true;
        for(int j = 0; j < temp.size(); j++){
            if (temp[j] != solution[i][j]){
                test = false;
                break;
            }
        }
        if (test) return true;
    }
    return false;
}

void solve(vector<int>& temp, vector<int>& candidates, int target, int idx){
    if (target < 0 || idx >= candidates.size()) return;
    else if (target == 0 && !check(temp)){
        solution.push_back(temp);
    } else {
        temp.push_back(candidates[idx]);
        solve(temp, candidates, target - candidates[idx], idx);
        temp.pop_back();
        
        if (idx < candidates.size() - 1){
            temp.push_back(candidates[idx + 1]);
            solve(temp, candidates, target - candidates[idx + 1], idx + 1);
            temp.pop_back();
            solve(temp, candidates, target, idx + 1);
        }
    }
}

vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
	solution.clear();
    vector<int> temp;
    solve(temp, candidates, target, 0);
    return solution;
}

int main(){
	vector<int> candidates;
	int target = 0, n = 0, temp = 0;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		candidates.push_back(temp);
	}
	cin >> target;                     
	combinationSum(candidates, target);
	if(solution.size() == 0)
		cout << "Empty\r\n";
	else
		for(int j = 0; j < solution.size(); j++){
			for(int k = 0; k < solution[j].size(); k++){
				cout << solution[j][k];
				if (k != solution[j].size() - 1) cout << " ";
			}
			cout << "\r\n";
		}
	
	return 0;
}
