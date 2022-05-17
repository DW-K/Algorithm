#include<iostream>
#include<queue>
#include<vector>
#include<stack>

#define MAX_SIZE 8

using namespace std;

typedef struct Point {
	int x;
	int y;
}Point;

queue<Point> w_q;

int table[MAX_SIZE][MAX_SIZE];
int temp_table[MAX_SIZE][MAX_SIZE];

int w_visit[MAX_SIZE][MAX_SIZE];
int v_visit[MAX_SIZE][MAX_SIZE];

vector<Point> v_points;

const int INF = 2.1e+10;

int N, M;
int res = INF;

int mv[][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; 

inline void copy_table() {
	copy(&table[0][0], &table[0][0] + MAX_SIZE * MAX_SIZE, &temp_table[0][0]);
}

void print_table() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << temp_table[i][j] << " ";
		}
		cout << "\n";
	}
}

void print_visit() {
	int count = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (v_visit[i][j] == 1) {
				count++;
			}
			cout << v_visit[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "--------" << count << '\n';
}

bool check_valid_index(int i, int j) {
	if (i < 0 || j < 0 || N <= i || M <= j)
		return false;
	return true;
}

void check_virus(int v_x, int v_y) {
	queue<Point> v_q;
	int x, y;
	int count = 0;

	v_q.push(Point{ v_x, v_y });

	cout << "start: " << v_x << ", " << v_y << "\n";

	while (!v_q.empty()) {
		Point p = v_q.front();
		v_q.pop();

		count++;

		if (v_visit[p.y][p.x] == 1) {
			continue;
		}
		
		cout << "visit: " << p.x << ", " << p.y << "  " << temp_table[p.y][p.x] <<"\n";

		v_visit[p.y][p.x] = 1;

		//print_visit();
		
		for (int i = 0; i < 4; ++i) {
			x = p.x + mv[i][0];
			y = p.y + mv[i][1];

			if (check_valid_index(x, y)) {
				if (temp_table[p.y][p.x] == 2 && temp_table[y][x] == 0) {
					temp_table[y][x] = 2;
				}

				if (v_visit[y][x] == 0 && temp_table[y][x] != 1) {
					v_q.push(Point{ x, y });
				}
			}
		}
	}
	cout << "count: " << count << '\n';
}

void check_wall() {
	int count = 0;
	while (count <= 3) {
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int temp_input;
	int v_x = -1, v_y = -1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> temp_input;
			table[i][j] = temp_input;

			if (temp_input == 2) {
				v_points.push_back(Point{ j, i });
			}
		}
	}
	cout << '\n';
	copy_table();

	print_table();

	for (auto p : v_points) {
		check_virus(p.x, p.y);
	}

	print_table();
}