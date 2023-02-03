#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int i = 0, j = 0, ans = 0;
	while (i < n && j < m) {
		if (a[i] + k < b[j]) i++;
		else if (a[i] - k > b[j]) j++;
		else {
			ans++; i++; j++;
		}
	}
	cout << ans << endl;
	return 0;
}