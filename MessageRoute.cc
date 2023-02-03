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
	vii path(n + 1, {-1, -1});
	queue<int> q; q.push(1);
	path[1].ff = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int &v : adj[u]) {
			if (path[v].ff != -1) continue;
			path[v] = { path[u].ff + 1, u };
			q.push(v);
		}
	}
	if (path[n].ff == -1) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	vi ans;
	while (n != -1) {
		ans.pb(n);
		n = path[n].ss;
	}
	reverse(all(ans));
	cout << ans.size() << endl;
	for (int &u : ans) cout << u << ' ';
	return 0;
}