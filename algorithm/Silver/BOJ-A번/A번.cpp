#include<stdio.h>
#include<vector>

typedef long long ll;
int N;
std::vector<ll> table;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		ll temp;
		scanf("%lld", &temp);
		table.push_back(temp);
	}

	ll res = table[0] > table[N-1] ? table[0] : table[N-1];

	for (int i = 1; i < N - 1; ++i) {
		ll temp = table[i - 1] > table[i + 1] ? table[i + 1] : table[i - 1];	// return smaller one
		temp += table[i];
		res = res > temp ? res : temp;
	}
	printf("%lld\n", res);
}