#include<iostream>
#include <functional>
#include <queue>

using namespace std;

#define MAX 500000

int N;
int input[MAX];

//class min_heap {
//	public:
//	int* data;
//	int heap_count;
//
//	min_heap() {
//		data = new int(MAX + 1);
//		heap_count = 0;
//	}
//
//	~min_heap() {
//		delete data;
//	}
//
//	void push(int value) {
//		data[++heap_count] = value;
//
//		int child = heap_count;
//
//		while (child > 1 && data[child >> 1] > data[child]) {
//				swap(data[child >> 1], data[child]);
//				child >>= 1;
//		}
//	}
//
//	int pop() {
//		int res = data[heap_count];
//		swap(data[1], data[heap_count--]);
//		
//		int parent = 1;
//		int child;
//
//		while (true) {
//			child = parent << 1;
//			if (data[parent] > data[child]) {
//				swap(data[parent], data[child]);
//				parent = child;
//			}
//			else if (data[parent] > data[child+1]) {
//				swap(data[parent], data[child + 1]);
//				parent = child;
//			}
//			else
//				break;
//		}
//
//		return res;
//	}
//};

int binary_search(int target, int is_lower) {
	int start = 0, end = N;
	int mid;

	while (start <= end) {
		mid = (start + end) >> 1;

		if (input[mid] < target + is_lower)
			start = mid + 1;
		else {
			end = mid;
		}
	}
	return end + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0;		// 평균, 중앙값, 최빈값, 범위

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> input[i];
		sum += input[i];
	}

	priority_queue< int, vector<int>, greater<int> > pq;

	for (int i = 0; i < N; ++i) {
		pq.push(input[i]);
	}

	int target = pq.top();
	int max_count = 0;
	int count = 0;

	int second_flag = 0;

	for (int i = 0; i < N; ++i) {
		input[i] = pq.top();
		pq.pop();

		if (input[i] == target) {
			count++;
		}
		else {
			target = input[i];
			count = 1;
			max_count = max_count < count ? count: max_count;
		}
	}

	cout << sum / N << '\n';
	cout << input[N / 2] << '\n';
	cout << max_count << '\n';
	if (N == 1) {
		cout << input[0] << '\n';
	}
	else {
		cout << (input[N - 1] - input[0]) << '\n';
	}
}