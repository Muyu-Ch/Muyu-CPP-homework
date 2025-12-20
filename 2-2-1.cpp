#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> suanfa(int k1, int k2, int n, vector<int> arg) {
	vector<int> arr;

	if (k1 > k2) {
		arr = { -1, -1 };
	}
	else {
		int left = 0;
		int right = n - 1;
		int current = 0;
		while (current <= right) {

			if (arg[current] < k1) {
				swap(arg[current], arg[left]);
				current++;
				left++;
			}

			else if (arg[current] >= k2) {
				swap(arg[current], arg[right]);
				right--;
			}
			else {
				current++;
			}
			arr = { left - 1,right + 1 };
		}
		return arr;
	}
}

int main() {
	int K1, K2;
	int N;
	
	cin >> K1 >> K2;
	cin >> N;

	vector<int> L(N);
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}

	vector<int> result = suanfa(K1, K2, N, L);

	if (result[0] == -1 && result[1] == -1) {
		cout << "false" << endl;
	}
	else {
		cout << result[0] << " " << result[1] << endl;
	}


}