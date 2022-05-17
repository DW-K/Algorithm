#include<iostream>

using namespace std;

int const max_size = 41;

int dp[max_size][2];

int N;

void init_dp(int n) {
	for (int i = 0; i < n; ++i) {
		dp[i][0] = 0;
		dp[i][1] = 0;
	}
}

void dfs(int n) {
	if (n < 0) {
		return;
	}
	else if (n == 0) {
		dp[n][0]++;
		return;
	}
	else if (n == 1) {
		dp[n][1]++;
		return;
	}
	
	dfs(n - 1);
	dfs(n - 2);	
	
	// n:2 -> 0 , 1(1,1)	n:3 -> 2, 1(1, 2)	n:4 -> 3, 2 (2, 3)
	dp[n][0] = dp[n - 1][0] + dp[0][0];
	dp[n][1] = dp[n - 1][1] + dp[0][1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int n;
	for (int i = 0; i < N; ++i) {
		cin >> n;
		init_dp(n);
		dfs(n);
		cout << dp[n][0] << ' ' << dp[n][1] << '\n';
	}
}