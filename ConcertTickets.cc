#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, x;
	cin >> n >> m;
	multiset<int> tickets;
	for (int i = 0; i < n; i++) {
		cin >> x;
		tickets.insert(-x);
	}
	for (int i = 0; i < m; i++) {
		cin >> x;
		auto it = tickets.lower_bound(-x);
		if (it != tickets.end()) {
			cout << -*it << endl;
			tickets.erase(it);
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}