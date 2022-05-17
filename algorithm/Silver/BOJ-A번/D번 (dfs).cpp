#include<stdio.h>
#include<vector>
#include<queue>

#define MAXSIZE 3001

typedef long long ll;

struct Point {
	int x, y;
};

int N, M;
char table[MAXSIZE][MAXSIZE];
int visit[MAXSIZE][MAXSIZE];
std::vector<Point> st;
ll count = 0;

void clean_visit() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			visit[i][j] = false;
		}
	}
	
	for (int i = 0; i < st.size(); ++i) {
		visit[st[i].y][st[i].x] = true;
	}
}

void print_stack() {
	for (int i = 0; i < st.size(); ++i) {
		printf("(%d, %d) ", st[i].x, st[i].y);
		if (i != st.size() - 1) {
			printf("->");
		}
	}
	printf("\n");
}

void dfs(Point start) {
	int x = start.x;
	int y = start.y;

	if (visit[y][x]) {
		return;
	}

	visit[y][x] = true;
	st.push_back({ x, y });
	
	if (st.size() == N) {
		print_stack();
	}

	if (y + 1 < N) {
		dfs({ x, y + 1 });
	}
	if (x + 1 < M) {
		dfs({ x + 1, y });
	}

	visit[y][x] = false;
	st.pop_back();
}

int main() {
	N = 4, M = 5;

	dfs({ 0, 0 });
}