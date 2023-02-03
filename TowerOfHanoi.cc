#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n; cin >> n;
	vector<pair<int, int>> ans = solve(1, 3, n);
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i.first << ' ' << i.second << endl;
	}
	return 0;
}