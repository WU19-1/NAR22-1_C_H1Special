#include<stdio.h>
#include<string.h>

char arr[10001][101] = {"b", "z", "h", "vv"};
char temp[10001][101];

void mergesort(int left, int right){
	if(left == right) return;
	int mid = (left + right) / 2;
	
	mergesort(left, mid);
	mergesort(mid + 1, right);
	
	int i = left, j = mid + 1, idx = 0;
	while(i <= mid && j <= right){
		if (strcmp(arr[i], arr[j]) < 0){
			strcpy(temp[idx], arr[i++]);
		} else {
			strcpy(temp[idx], arr[j++]);			
		}
		idx++;
	}
	while(i <= mid){
		strcpy(temp[idx++], arr[i++]);
	}
	while(j <= right){
		strcpy(temp[idx++], arr[j++]);		
	}
	for(int k = left; k <= right; k++){
		strcpy(arr[k], temp[k - left]);
	}
}

int main(){
	mergesort(0, 3);
	for(int i = 0 ; i < 4 ;  i++){
		printf("%s\n", arr[i]);
	}
	
	return 0;
}
