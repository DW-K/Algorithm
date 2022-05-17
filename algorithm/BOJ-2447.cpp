#include<iostream>
#include<cmath>

#define max_size 81*81

using namespace std;

int table[max_size][max_size];

int N;

void print_table() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (table[i][j] == 1) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';
	}
}

void init_table() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			table[i][j] = 1;
		}
	}
	table[1][1] = 0;
}

void mk_table(int n) {
	int size = int(pow(3, n));

	if (size > N) {
		return;
	}

	for (int n = 1; n < N; n * 3) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (i == 0 && j == 0)
					continue;
				if (i != 1 || j != 1) {
					for (int k = 0; k < size; ++k) {
						for (int l = 0; l < size; ++l) {
							table[k + i * size][l + j * size] = table[k][l];
						}
					}
				}
			}
		}
	}

	mk_table(n + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	init_table();
	mk_table(0);

	print_table();
}