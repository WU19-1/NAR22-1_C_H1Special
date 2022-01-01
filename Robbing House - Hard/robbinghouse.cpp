#include<stdio.h>
#include<string.h>

int memo[101];

int max(int a, int b){
	return (a > b) ? a : b;
}

int rob_rec(int* nums, int idx){
	if (idx < 0) return 0;
	
	if (memo[idx] >= 0) return memo[idx];
	
	int result = max(rob_rec(nums, idx - 2) + nums[idx], rob_rec(nums, idx - 1));
	memo[idx] = result;
	return result;
}

int rob(int* nums, int numsSize){
	memset(memo, -1, sizeof(memo));
	return rob_rec(nums, numsSize - 1);
}

int main(){
	
	int nums[] = {1,2,3,1};

	int size = sizeof(nums)/sizeof(int);

	printf("%d\n", rob(nums, size));
	
	return 0;
}
