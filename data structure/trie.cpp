#include<iostream>
#include<vector>

using namespace std;

struct Node {
	int finish;
	char C;

	Node(char C_) {
		finish = false;
		C = C_;
		printf("%c\n", C);
	}
};

vector<vector<Node>> Trie;

void insert(string str) {
	vector<Node> tempVec;
	for (int i = 0; i < str.size(); ++i) {
		tempVec.push_back(Node(str[i]));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string temp = "apple";
	insert(temp);
}