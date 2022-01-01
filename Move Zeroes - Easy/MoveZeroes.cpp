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
	
	return 0;
}
