#include<stdio.h>
int main() {
	int T;
	scanf("%d", &T);
	int x, y, z;
	for (int t = 0; t < T; ++t) {
		scanf("%d %d %d", &x, &y, &z);
		x &= 1; y &= 1; z &= 1;
		if (x + y + z < 2) printf("R\n"); else printf("B\n");
	}
}