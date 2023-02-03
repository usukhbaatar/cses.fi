#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int main() {
	int n; cin >> n;
	int x = 1;
	while (n--) {
		x = (x * 2) % mod;
	}
	cout << x << endl;
	return 0;
}