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

const int mod = 1e9 + 7;
const int oo ((((1LL << 62) - 1) << 1) + 1);

int32_t main() {
	fastio;
	int n, m; cin >> m >> n;
	vector<vi>dp(n + 2, vi(m, 0));
	int x; cin >> x;
	if (x == 0) {
		rep1(i, n) dp[i][0] = 1;
	} else {
		dp[x][0] = 1;
	}
	rep1(i, m - 1) {
		int x; cin >> x;
		if (x == 0) {
			rep1(j, n) {
				dp[j][i] += dp[j - 1][i - 1];
				dp[j][i] += dp[j][i - 1];
				dp[j][i] += dp[j + 1][i - 1];
				dp[j][i] %= mod;
			}
		} else {
			dp[x][i] += dp[x - 1][i - 1];
			dp[x][i] += dp[x][i - 1];
			dp[x][i] += dp[x + 1][i - 1];
			dp[x][i] %= mod;
		}
	}
	int ans = 0;
	rep1(i, n) {
		ans += dp[i][m - 1];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}