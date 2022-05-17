#include<iostream>

using namespace std;

int N, M;
string input_data;

char table[2] = { 'I', 'O' };

int find_ioi(int s) {
	bool o_flag = 0;
	int count = 0;
	int i = 0;
	cout << "--------------" << "   "<< s <<"\n";
	while (count < 2*N + 1 && i < input_data.size()) {
		cout << "--------------\n";
		
		if (o_flag && input_data[i] == 'O') {
			cout << "111111111111111111\n";
			count++;
			o_flag = !o_flag;
		}
		else if (!o_flag && input_data[i] == 'I') {
			cout << "222222222222222222\n";
			count++;
			o_flag = !o_flag;
		}
		else {
			return 0;
		}
		i++;
	}
	return 1;
}

int ioi() {
	int res = 0;
	int i = 0;
	while(i < input_data.size() - (2 * N + 1)) {
		if (find_ioi(i)) {
			res++;
			i += 2*N;
		}
		i++;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;

	cin >> N;
	cin >> M;
	cin >> input_data;

	cout << ioi() << '\n';
}