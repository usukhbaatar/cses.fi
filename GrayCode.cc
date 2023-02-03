#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a = {0, 1};
	for (int i = 1; i < n; i++) {
		for (int &i : a) {
			i *= 2;
		}
		vector<int> b = a;
		for (int &i : b) {
			i++;
		}
		reverse(b.begin(), b.end());
		a.insert(a.end(), b.begin(), b.end());
	}
	for (int x : a) {
		for (int i = 0; i < n; i++) {
			cout << ((((1 << i) & x) > 0) ? 1 : 0);
		}
		cout << endl;
	}
	return 0;
}