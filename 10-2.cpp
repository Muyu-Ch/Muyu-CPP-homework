#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] <= pivot) {
            j--;
        }
        nums[i] = nums[j];
        while (i < j && nums[i] >= pivot) {
            i++;
        }
        nums[j] = nums[i];
    }
    nums[i] = pivot;
    return i;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotIdx = partition(nums, left, right);
    quickSort(nums, left, pivotIdx - 1);
    quickSort(nums, pivotIdx + 1, right);
}

void first10(vector<int>nums, ofstream& outfile) {
    for (int i = 0; i < 10; i++) {
        outfile << nums[i] << " ";
    }
}

int main() {
    fstream infile("in.txt");
    vector<int>nums;
    int n;
    while (infile>>n){
        nums.push_back(n);
    }
    infile.close();
    quickSort(nums,0,nums.size()-1);
    
    ofstream outfile("out.txt");
    first10(nums, outfile);
    outfile.close();

    return 0;
}