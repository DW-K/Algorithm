#include<iostream>
#include<queue>

using namespace std;

int N, M;

int table[100][100];
int visit[100][100];
int cost[100][100];

typedef struct Point {
	int x;
	int y;
}Point;

bool check_valid_index(int i, int j) {
	if (i < 0 || j < 0 || i >= M || j >= N)
		return false;

	return true;
}

int mv[][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

const int INF = 2.1e+9;

void bfs() {
	queue<Point> q;

	q.push(Point{ 0, 0 });

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cost[i][j] = INF;
		}
	}

	cost[0][0] = 1;
	visit[0][0] = 1;

	while (!q.empty()) {
		Point p = q.front();
		q.pop();

		//cout << "visit: " << p.x << ", " << p.y << "\n";

		for (int i = 0; i < 4; ++i) {
			int x = mv[i][0] + p.x;
			int y = mv[i][1] + p.y;

			if (check_valid_index(x, y) && table[y][x] == 1) {
				if (visit[y][x] == 0) {
					visit[y][x] = 1;
					q.push(Point{ x, y });
				}
				
				else {
					cost[p.y][p.x] = cost[p.y][p.x] < cost[y][x] ? cost[p.y][p.x]: cost[y][x] + 1;
				}
			}			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	string num_str;

	for (int i = 0; i < N; ++i) {
		cin >> num_str;

		for (int j = 0; j < M; ++j) {
			table[i][j] = num_str[j] - '0';
		}
	}

	bfs();

	cout << cost[N-1][M-1];
}