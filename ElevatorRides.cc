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
	int n, x; cin >> n >> x;
	vi a(n);
	rep(i, n) cin >> a[i];
	vii dp((1 << n), { n, x});
	auto merge = [&](pii &a, int w) -> pii {
		if (a.ss + w <= x) return {a.ff, a.ss + w};
		return {a.ff + 1, w};
	};
	dp[0].ff = 0;
	rep1(j, (1 << n) - 1) {
		rep(i, n) {
			if (j & (1 << i)) {
				pii x = merge(dp[j ^ (1 << i)], a[i]);
				minn(dp[j], x);
			}
		}
	}
	cout << dp[(1 << n) - 1].ff << endl;
	return 0;
}