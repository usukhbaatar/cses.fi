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

vi sssp(vvii& adj, int source) {
	int n = adj.size();
	vi path(n, -1);
	vb vis(n, 0);
	heap<pii> q;
	q.push({-0, source});
	while (!q.empty()) {
		auto curr = q.top(); q.pop();
		int &u = curr.ss, &dis = curr.ff;
		if (vis[u]) continue;
		vis[u] = 1; path[u] = -dis;
		for (auto &x : adj[u]) {
			int &v = x.ff, &e = x.ss;
			if (vis[v]) continue;
			q.push({dis - e, v});
		}
	}
	return path;
}

int32_t main() {
	fastio;
	int n, m; cin >> n >> m;
	vvii adj1(n + 1);
	vvii adj2(n + 1);
	rep(i, m) {
		int u, v, e;
		cin >> u >> v >> e;
		adj1[u].pb({ v, e});
		adj2[v].pb({ u, e});
	}
	vi from = sssp(adj2, n);
	vb vis(n + 1, 0);
	vi cnt(n + 1, 0);
	vi mn(n + 1, oo);
	vi mx(n + 1, 0);
	cnt[n] = 1;
	mx[n] = 0;
	mn[n] = 0;
	function<int(int)> dfs = [&](int u) {
		if (vis[u]) return cnt[u];
		vis[u] = 1;
		for (auto [v, e] : adj1[u]) {
			if (from[u] - e != from[v]) continue;
			int c = dfs(v);
			if (c == 0) continue;
			cnt[u] += c;
			cnt[u] %= mod;
			mn[u] = min(mn[u], mn[v] + 1);
			mx[u] = max(mx[u], mx[v] + 1);
		}
		return cnt[u];
	};
	cout << from[1] << ' ' << dfs(1) << ' ' << mn[1] << ' ' << mx[1] << endl;
	return 0;
}