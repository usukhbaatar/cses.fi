#include <iostream>
using namespace std;

int main() {
	int n, k, a;
	cin >> n;
	k = n;
	for (int i = 1; i < n; i++) {
		cin >> a;
		k ^= a ^ i;
	}
	cout << k << endl;
	return 0;
}