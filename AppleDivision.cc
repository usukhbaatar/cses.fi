#include <string>
#include <iostream>
using namespace std;

int main() {
	int n, a[20];
	long long D = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		D += a[i];
	}
	for (int m = 0; m < (1 << n); m++) {
		long long A = 0, B = 0;
		for (int i = 0; i < n; i++) {
			if (m & (1 << i)) {
				A += a[i];
			} else {
				B += a[i];
			}
		}
		D = min(D, abs(A - B));
	}
	cout << D << endl;
	return 0;
}