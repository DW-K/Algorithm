#include<iostream>
#include<vector>

#define MAX 100000

using namespace std;
typedef long long ll;

vector<ll> hashingTable[MAX];

int N, M;
ll s_i = 1;
ll s = s_i << 31;

ll hashing(ll idx) {
	return (s + idx) % MAX;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	ll temp;
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		hashingTable[hashing(temp)].push_back(temp);
	}

	cin >> M;

	for (int i = 0; i < M; ++i) {
		cin >> temp;

		vector<ll> const vec = hashingTable[hashing(temp)];
		int flag = false;

		for (size_t i = 0; i < vec.size(); ++i) {
			if (vec[i] == temp) {
				cout << 1 <<'\n';
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << 0 << '\n';
		}
	}
}