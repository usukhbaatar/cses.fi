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

vi sssp(vvii& adj, int source, int dest, int k) {
	int n = adj.size();
	vvi path(n);
	vi vis(n, 0);
	heap<pii> q;
	q.push({-0, source});
	while (!q.empty()) {
		auto curr = q.top(); q.pop();
		int &u = curr.ss, &dis = curr.ff;
		if (vis[u] == k) continue;
		vis[u]++; path[u].pb(-dis);
		if (vis[dest] == k) return { path[u] };
		for (auto &x : adj[u]) {
			int &v = x.ff, &e = x.ss;
			if (vis[v] == k) continue;
			q.push({dis - e, v});
		}
	}
	return path[dest];
}

int32_t main() {
	fastio;
	int n, m, k;
	cin >> n >> m >> k;
	vvii adj(n);
	rep(i, m) {
		int u, v, e;
		cin >> u >> v >> e;
		adj[u - 1].pb({v - 1, e});
	}
	vi path = sssp(adj, 0, n - 1, k);
	for (int &x : path) cout << x << ' ';
	cout << endl;
	return 0;
}