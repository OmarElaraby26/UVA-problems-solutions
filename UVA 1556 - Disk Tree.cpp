#include <bits/stdc++.h>
using namespace std;

void PrintSpaces(const int x) {
	for (int i = 0; i < x; ++i) {
		cout << ' ';
	}
}

class Trie {
private:
	map<string, Trie*> child;
public:
	Trie() {
	}

	void insert(const vector<string> &line, const int idx = 0) {
		if (idx >= (int) line.size()) return;
		const string &key = line[idx];
		if (child[key] == nullptr) child[key] = new Trie();
		child[key]->insert(line, idx + 1);
	}

	void print(const int dep) {
		for (const auto &it : child) {
			PrintSpaces(dep);
			cout << it.first << '\n';
			it.second->print(dep + 1);
		}
	}

};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	while (cin >> n) {
		Trie tr;
		for (int x = 0; x < n; ++x) {
			string line;
			cin >> line;
			vector<string> path;
			for (int i = 0, j = 0; i < (int) line.size(); ++i) {
				string temp = "";
				while (j < (int) line.size() && line[j] != '\\') {
					temp += line[j++];
				}
				i = j++;
				path.emplace_back(temp);
			}
			tr.insert(path);
		}

		tr.print(0);
		cout << '\n';
	}
	return 0;
}

