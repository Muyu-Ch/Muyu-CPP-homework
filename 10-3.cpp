#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {

        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    fstream infile("in.txt");

    vector<int> arr;
    int num;
    while (infile >> num) {
        arr.push_back(num);
    }
    infile.close();

    shellSort(arr);

    ofstream outfile("out.txt");

    for (size_t i = 0; i < arr.size(); i++) {
        if (i > 0) outfile << " ";
        outfile << arr[i];
    }
    outfile.close();

    return 0;    
}