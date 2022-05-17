#include<stdio.h>
#include<queue>
#include<vector>

# define MAXSIZE 50
# define MAXINT (1 << 31) ^ -1	//MAXIMUMN INTEGER

struct Point {
	int x, y;
};

int N, M;
bool visit[MAXSIZE][MAXSIZE] = { 0, };

std::vector<std::vector<int>> table;
std::queue<Point> q;

int check_diff(int x, int y) {  //0 : Black, 1 : White
	int count = 0;
	int res_count;
	for (int k = 0; k <= 1; ++k) {	//k:0 => White first, k:1 => Black first
		for (int i = y; i < y + 8; ++i) {
			for (int j = x; j < x + 8; ++j) {
				int deter = ((i + j) & 1) ^ k;	//make checker board pattern
				if (deter == table[i][j]) {
					count++;
				}
			}
		}
		if (k == 0) {
			res_count = count;
			count = 0;
		}
		else {	//compare white first and black first
			res_count = res_count > count ? count : res_count;
		}
	}
	return res_count;
}

void visit_index(int target_i, int target_j) {
	if (target_i <= N - 8 && target_j <= M - 8 && !visit[target_i][target_j]) {
		q.push({ target_j, target_i });
		visit[target_i][target_j] = true;
	}
}

void bfs(Point start) {
	q.push(start);
	visit[start.x][start.y] = true;
	int res = MAXINT;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;

		int value = check_diff(x, y);
		res = res > value ? value : res;	// find minimum

		q.pop();

		for (int i = 0; i <= N - 8; ++i) {
			for (int j = 0; j <= M - 8; ++j) {
				int target_i = i, target_j = j + 1;
				visit_index(target_i, target_j);

				target_i = i + 1, target_j = j;
				visit_index(target_i, target_j);

			}
		}
	}
	printf("%d\n", res);
}

int main() {
	const Point start = { 0, 0 };
	char B[2] = { 'W', 'B' };

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i) {
		std::vector<int> vec;
		char temp[50];
		scanf("%s", &temp);

		for (int j = 0; j < M; ++j) {
			vec.push_back((temp[j] - 'B') & 1);
		}
		table.push_back(vec);
	}

	bfs(start);
}