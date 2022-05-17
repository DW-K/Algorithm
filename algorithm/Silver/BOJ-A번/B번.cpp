#include<stdio.h>
#include<vector>
int N, K;

std::vector<int> table;

int main() {
	scanf("%d %d", &N, &K);
	
	for (int i = 0; i < N; ++i) {
		int temp;
		scanf("%d", &temp);
		table.push_back(temp);
	}

	int temp = 0;
	for (int i = 0; i < K; ++i) {
		temp += table[i];
	}
	int res = temp;

	for (int i = 1; i < N; ++i) {
		temp -= table[i - 1];
		temp += table[(i + K - 1)%N];
		res = res > temp ? res : temp;
	}
	printf("%d\n", res);
}