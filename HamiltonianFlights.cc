#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define heap priority_queue
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
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;

const int mod = 1e9 + 7;
const int oo ((((1LL << 62) - 1) << 1) + 1);
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int dp[1 << 20][20];

int32_t main() {
	fastio;
	int n, m; cin >> n >> m;
	vvi adj(n);
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
	}
	//vvi dp(1 << n, vi(n, -1)); :( TLE
	memset(dp, -1, sizeof dp);
	function<int(int, int)> rec = [&](int mask, int i) {
		mask ^= (1 << i);
		if (i == n - 1) return (int)(mask == 0);
		if (dp[mask][i] != -1) return dp[mask][i];
		dp[mask][i] = 0;
		for (int j : adj[i]) {
			if (mask & (1 << j)) {
				dp[mask][i] += rec(mask, j);
				dp[mask][i] %= mod;
			}
		}
		return dp[mask][i];
	};
	cout << rec((1 << n) - 1, 0);
	return 0;
}
