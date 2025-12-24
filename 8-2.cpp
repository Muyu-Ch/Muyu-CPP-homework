#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> longestLenth(int n, vector<vector<int>> G, int v) {
	vector<int>longest;
	vector<int>leng(n,100);
	leng[v] = 0;

	queue<int>point;

	point.push(v);
	int len = 0;

	while (!point.empty() && len<n) {
		len++;
		size_t size = point.size();
		for (size_t j = 0; j < size;j++) {
			int a = point.front();
			point.pop();
			for (int i = 0; i < n; i++) {
				if (G[a][i] == 1) {
					point.push(i);
					if (leng[i] > len) {
						leng[i] = len;
					}
				}
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (leng[i] > max&&leng[i]<100) {
			max = leng[i];
		}
	}
	if (max == 0) { return{ -1 }; }

	for (int i = 0; i < n; i++) {
		if (leng[i] == max) {
			longest.push_back(i);
		}
	}

	return longest;
}

int main() {
	int n,v;
	cin >> n;
	vector<vector<int>> G;
	vector<int>line(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> line[j];
		}
		G.push_back(line);
	}
	cin >> v;

	vector<int>longest = longestLenth(n, G, v);
	for (size_t i = 0; i < longest.size(); i++) {
		cout << longest[i] << " ";
	}
	return 0;
}