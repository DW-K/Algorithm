#include<stdio.h>
#include<vector>
#include<queue>

#define MAX 3001

typedef long long ll;

struct Point {
	int x, y;
};

int N, M;
int P = 1e9 + 7;
int tf = 0;
ll table[2][MAX][MAX];
std::queue<Point> pos[2];

void print_t() {
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			printf("%lld ", table[tf][i][j]);
		}
		printf("\n");
	}
	printf("------------------\n");
}

ll recurrence(int i, int j) {
	return table[tf][i - 1][j] + table[tf][i][j - 1] - table[tf][i - 1][j - 1];
}

void make_next_table() {
	tf = !tf;
	int x = pos[tf].front().x;
	int y = pos[tf].front().y;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			table[tf][i][j] = recurrence(i, j);
			if (i == y && j == x) {
				table[tf][i][j] += table[!tf][i][j];
				if (!pos[tf].empty()) {
					pos[tf].pop();
					x = pos[tf].front().x;
					y = pos[tf].front().y;
				}
			}
		}
	}
}

int main() {
	//N = 4, M = 4;
	scanf("%d %d", &N, &M);

	char temp_str[MAX];

	for (int i = 1; i <= N; ++i) {
		scanf("%s", temp_str);
		for (int j = 1; j <= M; ++j) {
			table[tf][i][j] = recurrence(i, j);
			if (temp_str[j-1] == 'E') {
				table[tf][i][j] += 1;
			}
			else if (temp_str[j - 1] == 'S') {
				pos[!tf].push({ j, i });
			}
			else if (temp_str[j - 1] == 'M') {
				pos[tf].push({ j, i });
			}
		}
	}
	pos[tf].push({ -1,-1 });
	pos[!tf].push({ -1,-1 });
	
	//print_t();
	make_next_table();

	//print_t();
	make_next_table();

	//print_t();
	printf("%lld\n", table[tf][N][M] % P);
}
