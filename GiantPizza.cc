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

vi topsort(vvi& adj, int start = 1) {
	int n = adj.size();
	vb vis(n, 0);
	vi ans;
	function<void(int)> dfs = [&](int u) {
		if (vis[u]) return;
		vis[u] = 1;
		for (int &v : adj[u]) dfs(v);
		ans.pb(u);
	};
	for (int i = start; i < n; i++) {
		if (!vis[i]) dfs(i);
	}
	reverse(all(ans));
	return ans;
}

vvi transpose(vvi &adj) {
	vvi t(adj.size());
	int n = (int)adj.size();
	rep(i, n) {
		for (auto &x : adj[i]) {
			t[x].pb(i);
		}
	}
	return t;
}

int32_t main() {
	fastio;
	int n, m; cin >> m >> n;
	auto inv = [&](int x) -> int {
		return (x > n) ? x - n : x + n;
	};
	vvi adj1(2 * n + 1);
	rep(i, m) {
		char c1, c2;
		int u, v;
		cin >> c1 >> u >> c2 >> v;
		if (c1 == '-') u = inv(u);
		if (c2 == '-') v = inv(v);
		adj1[inv(u)].pb(v);
		adj1[inv(v)].pb(u);
	}
	vvi adj2 = transpose(adj1);
	vi v = topsort(adj1);
	vi labels(2 * n + 1, -1);
	vb vis(2 * n + 1, 0);
	int L = 0;
	function<void(int)> dfs = [&](int u) {
		if (vis[u]) return;
		vis[u] = 1; labels[u] = L;
		for (int &v : adj2[u]) {
			dfs(v);
		}
	};
	for (int &x : v) {
		if (!vis[x]) { ++L; dfs(x); }
	}
	rep1(i, n) {
		if (labels[i] == labels[inv(i)]) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}

	rep1(i, n) {
		if (labels[i] > labels[inv(i)]) {
			cout << "+ ";
		} else {
			cout << "- ";
		}
	}
	return 0;
}