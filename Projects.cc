#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define maxx(a, b) a = max(a, b)
#define minn(a, b) a = min(a, b)
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const int mod = 1e9 + 7;
const int oo ((((1LL << 62) - 1) << 1) + 1);

int32_t main() {
	fastio;
	int n; cin >> n;
	vvi p(n, vi(3));
	rep(i, n) cin >> p[i][0] >> p[i][1] >> p[i][2];
	sort(all(p), [&](vi &a, vi &b) {
		if (a[1] != b[1]) return a[1] < b[1];
		if (a[0] != b[0]) return a[0] < b[0];
		return a[2] < b[2];
	});
	map<int, int> dp;
	dp[0] = 0;
	for (auto &x : p) {
		auto it1 = dp.lower_bound(x[0]); it1--;
		auto it2 = dp.lower_bound(x[1]); it2--;
		int val = max(it1 -> second + x[2], it2 -> second);
		auto it = dp.find(x[1]);
		if (it != dp.end()) {
			maxx(it -> second, val);
		} else {
			dp[x[1]] = val;
		}
	}
	cout << dp[p.back()[1]] << endl;
	return 0;
}