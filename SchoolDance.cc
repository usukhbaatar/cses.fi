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

struct MaxMatch {
	vvi adj;
	vb vis;
	vi bull, cow;
	int B, C, start;
	MaxMatch(int n, int m, int start = 1) {
		this -> B = n;
		this -> C = m;
		this -> start = start;
		adj.resize(n + start);
		vis.resize(n + start);
		cow.resize(n + start, -1);
		bull.resize(m + start, -1);
	}
	void add_edge(int u, int v) {
		adj[u].pb(v);
	}

	bool dfs(int u) {
		if (vis[u]) return 0;
		vis[u] = 1;
		for (int &v : adj[u]) {
			if (bull[v] == -1) {
				bull[v] = u;
				cow[u] = v;
				return 1;
			}
		}
		for (int &v : adj[u]) {
			if (dfs(bull[v])) {
				vis[u] = 0;
				bull[v] = u;
				cow[u] = v;
				return 1;
			}
		}
		return 0;
	}
	vii solve() {
		bool done = 0;
		do {
			done = 1;
			fill(all(vis), 0);
			rep(i, B) {
				if (cow[i + start] == -1 && dfs(i + start)) {
					done = 0;
				}
			}
		} while (!done);
		vii pairs;
		rep(i, B) if (cow[i + start] != -1) {
			pairs.pb({i + start, cow[i + start]});
		}
		return pairs;
	}
};

int32_t main() {
	fastio;
	int n, m, e; cin >> n >> m >> e;
	MaxMatch match(n, m);
	rep(i, e) {
		int u, v;
		cin >> u >> v;
		match.add_edge(u, v);
	}
	vii pairs = match.solve();
	cout << pairs.size() << endl;
	for (pii &x : pairs) {
		cout << x.ff << ' ' << x.ss << endl;
	}
	return 0;
}
