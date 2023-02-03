#include <iostream>
using namespace std;

int main() {
	int n, k, t;
	long long s = 0;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> t;
		if (k > t) {
			s += (k - t);
		} else {
			k = t;
		}
	}
	cout << s << endl;
	return 0;
}