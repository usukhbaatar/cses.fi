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
	vector<pair<pii, int>> edges(m);
	vvi a(n + 1), b(n + 1);
	vb vis1(n + 1, 0), vis2(n + 1, 0);
	rep(i, m) {
		cin >> edges[i].ff.ff >> edges[i].ff.ss >> edges[i].ss;
		edges[i].ss *= -1;
		a[edges[i].ff.ff].pb(edges[i].ff.ss);
		b[edges[i].ff.ss].pb(edges[i].ff.ff);
	}

	function<void(int, vvi&, vb&)> dfs = [&](int u, vvi& adj, vb& vis) {
		if (vis[u]) return;
		vis[u] = 1;
		for (int &v : adj[u])
			dfs(v, adj, vis);
	};
	dfs(1, a, vis1);
	dfs(n, b, vis2);

	vi path(n + 1, oo);
	path[1] = 0;
	rep(i, n - 1) {
		for (auto &x : edges) {
			int &u = x.ff.ff, &v = x.ff.ss, &e = x.ss;
			if (path[u] != oo && path[u] + e < path[v]) {
				path[v] = path[u] + e;
			}
		}
	}

	for (auto &x : edges) {
		int &u = x.ff.ff, &v = x.ff.ss, &e = x.ss;
		if (path[u] != oo && path[u] + e < path[v]) {
			path[v] = path[u] + e;
			if (vis1[v] && vis2[v]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << -path[n] << endl;
	return 0;
}