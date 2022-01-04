#include<stdio.h>
#include<math.h>
#include<string.h>

char arr[100001] = "";
int sieve[100001] = {};
char res[100001][200];

int main(){
	int to = 0, n = 0;
	
	scanf("%d %d", &to, &n);
	getchar();
	
	scanf("%[^\n]", arr);
	getchar();
	
	int mul = 0;
	
	int lim = (int)(sqrt(n) + 1);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &mul);
		res[mul][sieve[mul]++] = arr[i];
		for(int j = mul + mul; j <= to; j += mul){
			res[j][sieve[j]++] = arr[i];
		}
	}
	
	getchar();
	
	for(int i = 1; i <= to; i++){
		if(strcmp(res[i], "") == 0) printf("%d\n", i % 10);
		else puts(res[i]);
	}
	
	return 0;
}

