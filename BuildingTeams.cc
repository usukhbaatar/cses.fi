#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define heap priority_queue;
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
		adj[v].pb(u);
	}
	vi color(n + 1, 0);
	function<void(int, int, int)> dfs = [&](int p, int u, int c) {
		if (color[u]) {
			if (color[u] == c) return;
			else {
				cout << "IMPOSSIBLE\n";
				exit(0);
			}
		}
		color[u] = c;
		for (int v : adj[u]) {
			if (v != p) dfs(u, v, c % 2 + 1);
		}
	};
	rep1(i, n) {
		if (!color[i]) {
			dfs(0, i, 1);
		}
	}
	rep1(i, n) cout << color[i] << ' ';
	cout << endl;
	return 0;
}