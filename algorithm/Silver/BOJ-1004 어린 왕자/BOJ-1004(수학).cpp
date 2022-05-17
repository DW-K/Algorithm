#include<stdio.h>
#include<vector>

int T;

int isInCircle(int x, int y, int cx, int cy, int r) {
	return (x - cx) * (x - cx) + (y - cy) * (y - cy) < r * r;
}

int main() {
	scanf("%d", &T);

	for (int t = 0; t < T; ++t) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int n;
		scanf("%d", &n);

		int count = 0;

		for (int i = 0; i < n; ++i) {
			int cx, cy, r;
			scanf("%d %d %d", &cx, &cy, &r);

			count += isInCircle(x1, y1, cx, cy, r) ^ isInCircle(x2, y2, cx, cy, r);
		}

		printf("%d\n", count);
	}
}
