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
	int N, n, m; cin >> n >> m;
	N = (1 << n);
	vvi adj(N), dp(m + 1, vi(N, 0));

	auto bit = [&](int m, int i) -> bool {
		return (m & (1 << i)) > 0;
	};
	auto can = [&](int m1, int m2) -> bool {
		rep(i, n) {
			if (bit(m1, i) && bit(m2, i))
				return 0;
			if (!bit(m1, i) && !bit(m2, i)) {
				if (i == n - 1) return 0;
				if (bit(m1, i + 1) || bit(m2, i + 1))
					return 0;
				i++;
			}
		}
		return 1;
	};

	rep(i, N) rep(j, N) {
		if (can(i, j)) adj[j].pb(i);
	}
	
	dp[0][0] = 1;
	rep1(i, m) rep(j, N) {
		for (int &x : adj[j]) {
			dp[i][j] += dp[i - 1][x];
			dp[i][j] %= mod;
		}
	}
	cout << dp[m][0] << endl;

	return 0;
}