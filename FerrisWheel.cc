#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, x, ans = 0;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int i = 0, j = n - 1;
	while (i <= j) {
		if (a[i] + a[j] <= x) {
			i++; j--;
		} else {
			j--;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}

