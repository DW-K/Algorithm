#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

int N;
map<string, int> keyMap;
map<int, string> valueMap;
int prune[15 * 1000];

struct Trie {
	vector<Trie*> node;
	int childCount;
	//int finish;

	Trie() {
		childCount = 0;
		//finish = false;
	}

	~Trie() {
		while (!node.empty()) {
			delete node.back();
			node.pop_back();
		}
	}

	int insert(vector<string>::iterator iter, vector<string>::iterator end) {
		if (iter == end) {
			return -1;
		}

		map<string, int>::iterator mapIter = keyMap.find(*iter);
		int nextIdx;

		if (mapIter != keyMap.end()) {	//string vector의 시작 element가 keyMap에 존재하면
			nextIdx = mapIter->second;
			// 해당 node에 trie 넣기
		}
		else {
			nextIdx = keyMap.size();
			keyMap.emplace(*iter, nextIdx);
			valueMap.emplace(nextIdx, *iter);
		}

		for (int i = node.size(); i <= nextIdx; ++i) {
			node.push_back(NULL);
		}

		if (node[nextIdx] == NULL) {
			node[nextIdx] = new Trie();
			childCount++;
		}
		if (node[nextIdx]->insert(iter + 1, end) == -1) {
			//finish = true;
			return;
		}
	}

	void find(int level) {
		set<string> foodSet;
		//cout << "level: " << level << '\n';
		for (int i = 0; i < valueMap.size(); ++i) {
			if (node.size() <= i && childCount <= foodSet.size()) {
				break;
			}
			if (node[i]) {
				foodSet.insert(valueMap.find(i)->second);
			}
		}

		for (auto& item : foodSet) {
			int idx = keyMap.find(item)->second;

			for (int j = 0; j < level; ++j) {
				cout << "--";
			}

			cout << valueMap.find(idx)->second << '\n';

			node[idx]->find(level+1);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	Trie trie;

	for (int i = 0; i < N; ++i) {
		int K;
		cin >> K;
		 
		vector<string> foodVec;

		string tempStr;

		for (int j = 0; j < K; ++j) {
			cin >> tempStr;
			foodVec.push_back(tempStr);
		}

		trie.insert(foodVec.begin(), foodVec.end());
	}
	trie.find(0);
}