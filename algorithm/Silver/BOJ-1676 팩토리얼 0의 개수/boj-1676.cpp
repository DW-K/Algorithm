#include<iostream>

using namespace std;

// 오늘의 교훈: 곱하기 문제는 곱하기로 남겨두자

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int divider = 1, res = 0;
	while (divider <= N) {
		divider *= 5;
		res += N / divider;
	}

	cout << res;
}