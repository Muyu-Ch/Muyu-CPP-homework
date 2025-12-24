//有一个含n（n<=200000）个整数的无序序列，设计一个算法利用快速排序思路求前10个最大的元素。(快速排序)


#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
	int i = left;
	int j = right;
	int point = nums[left];

	while (i < j) {
		while (i<j && nums[j]>point) {
			j--;
		}
		nums[i] = nums[j];
		while (i < j && nums[i] <= point) {
			i++;
		}
		nums[j] = nums[i];
	}
	nums[i] = point;
	return i;
}

void quickSort(vector<int>& nums, int left, int right) {
	if (left >= right) {
		return;
	}
	int i = partition(nums, left, right);
	partition(nums, left, i - 1);
	partition(nums, i + 1, right);
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	quickSort(nums, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << nums[i]<<" ";
	}
	
}
