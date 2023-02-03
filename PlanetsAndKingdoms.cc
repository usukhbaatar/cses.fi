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

pair<int, vi> tarjan(vvi &adj, int start = 1) {
	int n = adj.size() - start;
	vi vis(n + start, -1);
	vi low(n + start, oo);
	vb in(n + start, 0);
	stack<int> st;
	int timer = 0;
	int N = 0;
	vi res(n + start, -1);
	function<void(int)> dfs = [&](int u) {
		low[u] = vis[u] = ++timer;
		st.push(u); in[u] = 1;
		for (int &v : adj[u]) {
			if (vis[v] == -1) {
				dfs(v);
				minn(low[u], low[v]);
			} else if (in[v]) {
				minn(low[u], vis[v]);
			}
		}
		if (low[u] == vis[u]) {
			N++;
			while (st.top() != u) {
				res[st.top()] = N;
				in[st.top()] = 0; st.pop();
			}
			res[st.top()] = N;
			in[st.top()] = 0; st.pop();
		}
	};
	rep(i, n) {
		if (vis[i + start] != -1) continue;
		dfs(i + start);
	}
	return { N, res };
}

int32_t main() {
	fastio;
	int n, m; cin >> n >> m;
	vvi adj(n + 1);
	rep(i, m) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
	}
	auto ans = tarjan(adj, 1);
	cout << ans.ff << endl;
	for (int label : ans.ss) cout << label << ' ';
	cout << endl;
	return 0;
}