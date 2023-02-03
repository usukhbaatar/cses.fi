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
	vb in(n + 1, 0);
	vi path, ans;

	function<bool(int)> dfs = [&](int u) {
		if (in[u]) {
			ans.pb(u);
			for (int i = path.size() - 1; i >= 0; i--) {
				ans.pb(path[i]);
				if (path[i] == u) break;
			}
			return true;
		}
		if (vis[u]) return false;
		vis[u] = 1; in[u] = 1; path.pb(u);
		for (int &v : adj[u]) {
			if (dfs(v)) return true;
		}
		in[u] = 0; path.pop_back();
		return false;
	};
	bool found = 0;
	rep1(i, n) {
		if (!vis[i] && dfs(i)) {
			found = 1;
			break;
		}
	}
	if (!found) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	reverse(all(ans));
	cout << ans.size() << endl;
	for (int &u : ans) {
		cout << u << ' ';
	}
	cout << endl;
	return 0;
}