#include <iostream>
using namespace std;

long long solve(long long n) {
	return (n * n) * (n * n - 1) / 2 - 4 * (n - 1) * (n - 2);
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << solve(i) << endl;
	}
	return 0;
}