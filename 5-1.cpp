#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<sstream>
using namespace std;

class Solution {
public:
	int totalNQueens(int n){
		if (n <= 0)return 0;
		count = 0;
		vector<int> chess(n, -1);
		backTrack(chess, 0, n);
		return count;
	}

private:
	int count;
	bool isConflict(int row,int cal,vector<int>& chess) {
		for (int i = 0; i < row; i++) {
			if (chess[i] == cal || abs(chess[i] - cal) == abs(i - row)) {
				return true;
			}
		}
		return false;
	}
	void backTrack(vector<int>& chess,int row,int n) {
		if (row == n) {
			count++;
			return;
		}

		for (int cal = 0; cal < n; cal++) {
			if (isConflict(row, cal, chess)==false) {
				chess[row] = cal;
				backTrack(chess, row + 1, n);
			}
		}
	}
};

int main() {
	fstream infile("in.txt");
	int n;
	infile >> n;

	Solution Queen;
	cout<<Queen.totalNQueens(n)<<endl;

	return 0;
}
