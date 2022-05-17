#include<iostream>
#define MAX 100001

using namespace std;

int dp[MAX][3];

int M = 9901;
int N;

void init() {
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	init();

	for (int i = 1; i < N; ++i) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % M;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % M;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % M;
	}

	cout << (dp[N-1][0] + dp[N-1][1] + dp[N-1][2]) % M << '\n';
}