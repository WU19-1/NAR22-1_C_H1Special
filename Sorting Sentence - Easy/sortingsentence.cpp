#include<stdio.h>
#include<string.h>

char arr[1001][101];
char temp[1001][101];

void merge(int left, int right){
	if(left == right) return;
	int mid = (left + right) / 2;
	merge(left, mid);
	merge(mid + 1, right);
	
	int i = left, j = mid + 1, idx = 0;
	while(i <= mid && j <= right){
		if (strcmp(arr[i], arr[j]) < 0){
			strcpy(temp[idx], arr[i]);
			i += 1;
		} else {
			strcpy(temp[idx], arr[j]);
			j += 1;
		}
		idx += 1;
	}
	while(i <= mid){
		strcpy(temp[idx], arr[i]);
		idx += 1, i += 1;
	}
	while(j <= right){
		strcpy(temp[idx], arr[j]);
		idx += 1, j += 1;
	}
	for(int k = left; k <= right; k++){
		strcpy(arr[k], temp[k - left]);
	}
}

int main(){
	
	return 0;
}
