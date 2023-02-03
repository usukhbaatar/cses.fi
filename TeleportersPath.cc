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

vi euler_path(int n, int m, int start, vvii &adj, vi &deg) {
	rep1(i, n) {
		if (deg[i] & 1) return {};
	}
	vb vis(m, 0);
	stack<int> st; st.push(start);
	vi path; int cnt = 0;
	while (!st.empty()) {
		int v = st.top();
		bool flag = 0;
		while (!adj[v].empty()) {
			auto [u, idx] =  adj[v].back();
			adj[v].pop_back();
			if (!vis[idx]) {
				st.push(u); vis[idx] = 1;
				cnt++; flag = 1;
				break;
			}
		}
		if (!flag) { path.pb(v); st.pop(); }
	}
	if (cnt != m) return {};
	reverse(all(path));
	return path;
}

int32_t main() {
	fastio;
	int n, m; cin >> n >> m;
	vvii adj(n + 1);
	vi deg(n + 1, 0);
	rep(i, m) {
		int u, v; cin >> u >> v;
		adj[u].pb({v, i});
		deg[u]++; deg[v]++;
	}
	deg[1]++; deg[n]++;
	vi path = euler_path(n, m, 1, adj, deg);
	if (path.size() == 0) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	for (int u : path)
		cout << u << ' ';
	cout << endl;
	return 0;
}