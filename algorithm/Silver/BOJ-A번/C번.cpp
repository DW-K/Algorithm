#include<stdio.h>
#include<vector>

typedef long long ll;

ll N;

int main() {
	scanf("%lld", &N);

	ll bits = 1;
	ll bit_count = 0;
	while (bits <= N) {
		bits <<= 1;
		bit_count++;
	}

	//printf("bits: %d count: %d\n", bits, bit_count);
	
	if (bits-1 == N) {
		printf("1\n");
		printf("%lld\n", N);
	}
	else {
		printf("2\n");
		printf("%lld %lld\n", bits - 1 - N, N);
	}
}