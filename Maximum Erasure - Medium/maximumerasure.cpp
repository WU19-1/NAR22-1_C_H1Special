#include<bits/stdc++.h>

using namespace std;
bool check[10001];
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
	return 0;
}
