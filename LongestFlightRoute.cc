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

int32_t main() {
	fastio;
	int n, m; cin >> n >> m;
	vvi adj(n + 1);
	rep(i, m) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
	}
	vb vis(n + 1, 0);
	vi dis(n + 1, -1), to(n + 1, -1);
	vi ans; dis[n] = 0;
	function<int(int)> dfs = [&](int u) {
		if (vis[u]) return dis[u];
		vis[u] = 1;
		for (int &v : adj[u]) {
			int t = dfs(v);
			if (t != -1) t++;
			if (dis[u] < t) {
				dis[u] = t;
				to[u] = v;
			}
		}
		return dis[u];
	};
	if (dfs(1) == -1) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	int u = 1;
	while (u != n) {
		ans.pb(u);
		u = to[u];
	}
	ans.pb(n);
	cout << ans.size() << endl;
	for (int &i : ans) {
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}