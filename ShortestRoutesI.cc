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
	vvii adj(n + 1);
	rep(i, m) {
		int u, v, e;
		cin >> u >> v >> e;
		adj[u].pb({ v, e });
	}
	vi path(n + 1, -1);
	vb vis(n + 1, 0);
	heap<pii> q;
	path[1] = 0;
	q.push({-0, 1});
	while (!q.empty()) {
		pii curr = q.top(); q.pop();
		int u = curr.ss, dis = -curr.ff;
		if (vis[u]) continue;
		path[u] = dis; vis[u] = 1;
		for (pii &x : adj[u]) {
			if (vis[x.ff]) continue;
			q.push({-(dis + x.ss), x.ff });
		}
	}
	rep1(i, n) {
		cout << path[i] << ' ';
	}
	cout << endl;
	return 0;
}