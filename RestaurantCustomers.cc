#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define all(v) v.begin(), v.end()
#define maxx(a, b) a = max(a, b)
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

int main() {
	int n, s = 0, ans = 0, x, y; vii a;
	cin >> n;
	rep(i, n) {
		cin >> x >> y;
		a.pb({ x , 1}); a.pb({ y, -1});
	}
	sort(all(a));
	for (auto x : a) {
		s += x.ss;
		maxx(ans, s);
	}
	cout << ans << endl;
	return 0;
}