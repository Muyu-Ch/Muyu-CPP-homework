#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

void fix(string a, string b) {
	string result;
	int lenA = a.size();
	int lenB = b.size();
	int len=min(lenB,lenA);
	

	for (int i = len; i > 0;i--) {
		bool ifcorrect = true;
		for (int j = 0; j <i; j++) {
			if (a[j] != b[lenB - i + j]) {
				ifcorrect = false;
				break;
			}
		}

		if (ifcorrect) {
			
			for (int t = 0; t < i; t++) {
				cout << a[t];
			}
			cout << " ";
			cout << i << endl;
			return;
		}
	}

	cout << 0 << endl;
}

int main() {
	string a;
	string b;

	ifstream infile("in.txt");

	getline(infile, a);
	getline(infile, b);

	fix(a, b);

	return 0;
}