#include<bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int zeroCounter = 0, len = nums.size();
    for(int i = 0; i < len; i++){
        if(nums[i] != 0){
            nums[zeroCounter] = nums[i];
            zeroCounter += 1;
        }
    }
    for(int i = zeroCounter; i < len; i++){
        nums[i] = 0;
    }
}

int main(){
	int n = 0, temp = 0;
	vector<int> nums;
	
	cin >> n;
	for(int i = 0 ; i < n; i++){
		cin >> temp;
		nums.push_back(temp);
	}
	
	moveZeroes(nums);
	
	for(int i = 0 ; i < n ; i++){
		if(i == 0) printf("%d", nums[i]);
		else printf(" %d", nums[i]);
	}
	cout << endl;
	
	return 0;
}
