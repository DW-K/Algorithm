#include<stdio.h>

int fac(int x) {
	if (x == 1) {
		return 1;
	}
	return x * fac(x - 1);
}
// 1 1 2 3 5 8 13 21 34
int dp[1000];
int dp_index = 0;
int fib(int x) {
	if (x <= 1) {
		dp[dp_index++] = x;
		return 1;
	}
	dp[dp_index++] = fib(x - 2) + fib(x - 1);
}

int main() {
	/*int T;
	scanf("%d", &T);
	int x, y, z, temp;
	for (int t = 0; t < T; ++t) {
		scanf("%d %d %d", &x, &y, &z);
		if (x < y) {
			temp = x;
			x = y;
			y = temp;
		}
		if (y < z) {
			temp = y;
			y = z;
			z = temp;
		}
		if (x < y) {
			temp = x;
			x = y;
			y = temp;
		}

		
	}*/
	for (int i = 0; i < 10; ++i) {
		fib(i);
		printf("%d\n", dp[i]);
	}
}

// B R B
/*
3
1 1 1
1 3 2
2 3 2
*/

