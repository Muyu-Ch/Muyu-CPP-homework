//给你n个整数，请按从大到小的顺序输出其中前m大的数。

#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;

vector<int> queue(vector<int>nums) {
	bool ifover = false;
	for(size_t i=0;i<nums.size();i++){
		ifover = true;
		for (size_t j = 0; j < nums.size() - 1; j++) {
			if (nums[j] < nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
				ifover = false;
			}
		}
		if (ifover) { return nums; }
	}
	return nums;
}

void firstm(vector<int>nums,int m) {
	nums = queue(nums);
	for (int i = 0; i < m; i++) {
		cout << nums[i] << " ";
	}
}

int main() {
	int n, m;
	ifstream infile("in.txt");

	infile >> n >> m;
	vector<int>nums(n);
	for (int i = 0; i < n; i++) {
		infile >> nums[i];
	}
	infile.close(); 

	firstm(nums, m);
	return 0;

}
