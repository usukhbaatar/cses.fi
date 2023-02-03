#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int main() {
	long long n, s = 0; cin >> n;
	for (long long z = 5; z <= n; z *= 5) {
		s += n / z;
	}
	cout << s << endl;
	return 0;
}