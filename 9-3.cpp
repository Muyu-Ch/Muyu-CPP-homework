#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int forth(vector<vector<int>>nums, int n) {
	int count = 0;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					if (nums[0][i] + nums[1][j] + nums[2][k] + nums[3][l] == 0) {
						count++;
					}
				}
			}
		}
	}
	return count;
}

int main() {
	int n;
	ifstream infile("in.txt");
	infile >> n;
	vector<vector<int>>nums(4);
	int a;
	for (int i = 0; i < n; i++) {
		infile>> a;
		nums[0].push_back(a);
		infile >> a;
		nums[1].push_back(a);
		infile >> a;
		nums[2].push_back(a);
		infile >> a;
		nums[3].push_back(a);
	}

	cout << forth(nums, n) << endl;
	return 0;
}