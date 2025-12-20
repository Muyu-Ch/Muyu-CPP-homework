#include<iostream>
using namespace std;

void threePlusOne(int n) {
	while (n != 1) {
		cout << n << "->";
		int a = n;
		if (a % 2 == 0) {
			n = n / 2;
		}
		else {
			n = n * 3 + 1;
		}
	}
	cout << 1 << endl;
}

int main() {
	threePlusOne(100);
	return 0;
}