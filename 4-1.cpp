#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int clothesNumber(string a, string b) {
	int count = 0;

	int lenA = a.size();
	int lenB = b.size();

	if (lenA < lenB) {
		return count;
	}

	int i = 0;
	while (i <= lenA - lenB) {
		bool ifmatch = true;
		for (int j = 0; j < lenB; j++) {
			if (a[i + j] != b[j]) {
				ifmatch = false;
				break;
			}
		}

		if (ifmatch) {
			count++;
			i += lenB;
		}

		else { i++; }
	}

	return count;
}

int main() {
	string line;
	getline(cin, line);
	istringstream iss(line);
	string A, B;
	iss >> A >> B;

	int count = 0;

	if (A == "#" || B == "#") {
		count = 0;
	}

	count = clothesNumber(A, B);
	cout << count << endl;
	return 0;
}