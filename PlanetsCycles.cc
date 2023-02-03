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
	int n; cin >> n;
	vi a(n + 1);
	rep1(i, n) cin >> a[i];
	vi root(n + 1, 0), color(n + 1, 0);
	vi to(n + 1, 0), sz(n + 1, 0);
	vi idx(n + 1, 0), level(n + 1, 0);
	vb in(n + 1, 0);
	vi path;
	auto cycle = [&](int u) -> void {
		bool found = 0; int id = 0;
		for (int &v : path) {
			if (v == u) found = 1;
			if (!found) continue;
			idx[v] = id++;
			root[v] = u;
			color[v] = 1;
			to[v] = v;
		}
		sz[u] = id;
	};
	function<int(int)> dfs = [&](int u) {
		if (in[u]) {
			cycle(u);
			return u;
		}
		if (color[u]) {
			return root[u];
		}
		in[u] = 1; path.pb(u);
		int &v = a[u];
		root[u] = dfs(v);
		if (color[u] == 0) {
			color[u] = 2;
			to[u] = to[v];
			level[u] = level[v] + 1;
		}
		in[u] = 0; path.pop_back();
		return root[u];
	};
	rep1(i, n) {
		if (color[i] == 0)
			dfs(i);
	}
	rep1(i, n) {
		int u = i, ans = 0;
		ans += level[u];
		u = to[u];
		ans += sz[root[u]];
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}