#include <string>
#include <iostream>
using namespace std;

int main() {
	int c[26] = {0};
	string s; cin >> s;
	for (char i : s) {
		c[i - 'A']++;
	}
	int m = -1;
	for (int i = 0; i < 26; i++) {
		if (c[i] & 1) {
			if (m != -1) {
				cout << "NO SOLUTION\n";
				return 0;
			}
			m = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < c[i] / 2; j++) {
			cout << (char)(i + 'A');
		}
	}
	if (m != -1) {
		cout << (char)(m + 'A');
	}
	for (int i = 25; i >= 0; i--) {
		for (int j = 0; j < c[i] / 2; j++) {
			cout << (char)(i + 'A');
		}
	}
	return 0;
}
