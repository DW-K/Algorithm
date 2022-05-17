#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int max_size = 100001;
const int inf = 2.1e+9;

int N;
ll dist[max_size];
ll price[max_size];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int temp;
	for (int i = 0; i < N - 1; ++i)
		cin >> dist[i];

	for (int i = 0; i < N; ++i) {
		cin >> price[i];
	}

	price[N - 1] = inf;

	ll cost = 0;
	// i: 기준, j: 비교
	int i = 0, j = 1;
	while (i < N) {
		j = i + 1;
		ll d = -dist[i];
		cost += dist[i] * price[i];
		while (j <= N) {
			d += dist[j - 1];
			if (price[i] < price[j]) {
				j++;
			}
			else {
				break;
			}
		}
		cost += d > 0 ? price[i] * d : 0;
		i = j;
	}

	cout << cost;
}