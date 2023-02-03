#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define maxx(a, b) a = max(a, b)
#define minn(a, b) a = min(a, b)
#define rep(i, n) for (int i = 0; i < n; i++)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int mod = 1e9 + 7;
const int oo ((((1 << 30) - 1) << 1) + 1);

int main() {
	int n, x, y; vii a;
	cin >> n;
	vi dp(n, 1);
	rep(i, n) {
		cin >> x >> y;
		a.pb({ y , x});
	}
	sort(all(a));
	rep(i, n) {
		if (i > 0) dp[i] = dp[i - 1];
		auto it = lower_bound(all(a), mp(a[i].ss, oo));
		int j = it - a.begin() - 1;
		if (j >= 0) maxx(dp[i], dp[j] + 1);
	}
	cout << dp[n - 1] << endl;
	return 0;
}