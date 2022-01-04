#include<bits/stdc++.h>

using namespace std;
bool check[10001];

int maximumUniqueSubarray(vector<int>& nums) {
    memset(check, false, sizeof(check));
    int left = 0, right = 1, len = nums.size(), m = 0, sum = 0;
    m = sum = nums[0];
    check[nums[0]] = true;
    while(right <= len - 1){
        if(!check[nums[right]]){
            check[nums[right]] = true;
            sum += nums[right];
            right += 1;
            if (sum > m){
                m = sum;
            }
        } else {
            sum -= nums[left], check[nums[left]] = false;
            left += 1;
        }
    }
    return m;
}

int main(){
	int n = 0, temp = 0;
	vector<int> nums;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		nums.push_back(temp);
	}
	
	cout << maximumUniqueSubarray(nums) << endl;
	
	return 0;
}
