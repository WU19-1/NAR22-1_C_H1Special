#include<stdio.h>
#include<math.h>

unsigned long long gcd(unsigned long long a, unsigned long long b){
	unsigned long long temp = 0;
	while (b != 0){
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main(){
	
	unsigned long long count = 0, n = 0;
	
	scanf("%llu %llu", &count, &n);
	getchar();
	
	char arr[n + 1] = "";
	unsigned long long multiples[n + 1];
	
	scanf("%[^\n]", arr);
	getchar();
	
	unsigned long long gcd_all = 0;
	unsigned long long total_all = 0;
	
	
	for(int i = 0; i < n; i++){
		scanf("%llu", &multiples[i]);
//		if (i != 0){
//			if (gcd_all == 0){
//				gcd_all = multiples[i - 1] * multiples[i] / gcd(multiples[i - 1], multiples[i]);
//			} else {
//				gcd_all = gcd_all * multiples[i] / gcd(gcd_all, multiples[i]);
//			}
//		}
	}
//	printf("%llu\n", gcd_all);
	getchar();
	
	for(int i = 0 ; i < n; i++){
		
	}
	
	return 0;
}
