#include<stdio.h>
#include<vector>

struct Point {
	int x, y;
};

typedef long long ll;

std::vector<char> st;
ll tree[3001*2];
int visit[3001][3001];
char table[3001][3001];

ll result = 0;
int N, M;
int bit;

void print_tree() {
	int count = 0;
	int two_square[10];
	for (int i = 0; i < 10; ++i) {
		two_square[i] = 2 << i;
	}
	for (int i = 1; i < bit * 2; ++i) {
		printf("%d ", tree[i]);
		if (i == two_square[count] - 1) {
			count++;
			printf("\n");
		}
	}
}

void init() {
	for (bit = 1; bit < N; bit <<= 1) {};

	for (int i = 1; i < bit * 2; ++i) {
		tree[i] = 0;
	}
}

void update_util(int idx, int value) {
	idx += bit;

	while (idx > 0) {
		tree[idx] += value;
		idx >>= 1;
	}
}

void update(int idx, int value) {
	update_util(idx, value - tree[idx + bit]);
}

int getSum(int s, int e) {
	s += bit;
	e += bit;
	int res = 0;

	while (s <= e) {
		if ((s & 1) == 1) {
			res += tree[s];
		}

		if ((e & 1) == 0) {
			res += tree[e];
		}

		s = (s+1) >> 1;
		e = (e-1) >> 1;
	}

	return res;
}

void print_stack() {
	for (auto& item : st) {
		printf("%c -> ", item);
	}
	printf("\n\n");
}

void index_tree() {
	init();
	int idx = 0;
	int e_flag = 0;
	int e_count = 0;
	int s_count = 0;
	std::vector<int> m_st;
	for (int i = 0; i < st.size(); ++i) {
		if (st[i] == 'E') {
			e_flag = 1;
		}
		else if (st[i] == 'S' && e_flag == 1) {
			s_count++;
		}
		else if (st[i] == 'M') {
			e_flag = 0;
			m_st.push_back(idx);
			update(idx++, s_count);
			s_count = 0;
		}
	}
	/*printf("------------------------\n");
	print_tree();
	printf("------------------------\n");*/

	for (int i = 0; i < m_st.size(); ++i) {
		int m_idx = m_st.back();
		m_st.pop_back();

		for (int j = 0; j <= m_idx; ++j) {
			result += getSum(j, m_idx);
			result = result % (1000000000 + 7);
		}
	}
	//printf("res: %lld\n", result);
}

void dfs_util(Point start) {
	// stack 에서 다시 빼기
	// visit 체크

	int x = start.x;
	int y = start.y;

	if (visit[y][x] || y >= N) {
		return;
	}

	//printf("-------------------------visit: (%d, %d)\n", x, y);

	visit[y][x] = 1;
	st.push_back(table[y][x]);

	if (st.size() == N) {
		//print_stack();
		index_tree();
		
		st.pop_back();
		visit[y][x] = 0;
	}
	else {
		for (int j = x; j < M; ++j) {
			dfs_util({ j, y + 1 });
		}

		st.pop_back();
		visit[y][x] = 0;
	}
}

void dfs() {
	for (int j = 0; j < M; ++j) {
		dfs_util({ j, 0 });
	}
}

int main() {
	////N = 6, M = 4;
	//scanf("%d %d", &N, &M);

	////char B[3] = { 'E', 'S', 'M' };
	//char temp_str[3001];

	//for (int i = 0; i < N; ++i) {
	//	scanf("%s", temp_str);
	//	for (int j = 0; j < M; ++j) {
	//		//table[j][i] = B[((i*2 + j)*13) % 3];
	//		table[i][j] = temp_str[j];
	//	}
	//}

	N = 3000, M = 3000;

	char B[3] = { 'E', 'S', 'M' };
	char temp_str[3001];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			table[i][j] = B[((i + j) * 7) % 3];
		}
	}

	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%c ", table[j][i]);
		}
		printf("\n\n");
	}*/

	dfs();

	printf("%d\n", result);
}