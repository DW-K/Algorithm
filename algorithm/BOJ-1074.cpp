#include<iostream>
#include<cmath>

using namespace std;

int N;
int C, R;
typedef long long ll;
ll cnt = 0;

int coord_filter[4][2] = {
	{0, 0}, {1, 0}, {0, 1}, {1, 1}
};

void traverse(int c, int r, int n) {
	double interver = n / 2;
	int temp_c, temp_r;
	double quat_c, quat_r;

	if (c == C && r == R) {
		return;
	}

	for (int i = 0; i < 4; ++i) {
		temp_c = c + coord_filter[i][0] * interver;
		temp_r = r + coord_filter[i][1] * interver;

		quat_c =  c + (interver - 0.5);
		quat_r =  r + (interver - 0.5);
		
		if (0 <= (temp_c - quat_c) * (C - quat_c) &&
			0 <= (temp_r - quat_r) * (R - quat_r) ) {
			traverse(temp_c, temp_r, n / 2);
			return;
		}

		cnt += (interver) * (interver);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R >> C;
	
	traverse(0, 0, pow(2, N));
	
	cout << cnt << '\n';
}