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

struct MaxFlow {
	struct Edge {
	int u, v, cap, flow;
		Edge(int u, int v, int c) : flow(0) {
			this -> u = u;
			this -> v = v;
			this -> cap = c;
		}
	};

	int n, source, sink, start;
	vector<Edge> edges;
	vvi adj;
	vector<vi::iterator> it;
	vi dist;

	MaxFlow(int n, int start = 1) {
		this -> n = n;
		this -> start = start;
		adj.resize(n + start);
		it.resize(n + start);
		dist.resize(n + start);
	}

	void add_edge(int u, int v, int e) {
		if (u == v) return;
		edges.emplace_back(u, v, e);
		adj[u].pb(edges.size() - 1);
	}

	bool bfs() {
		memset(&dist[0], -1, sizeof(dist[0]) * dist.size());
		dist[source] = 0;
		queue<int> q;
		q.push(source);
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for (auto &i : adj[u]) {
				Edge &e = edges[i];
				if (e.flow < e.cap && dist[e.v] == -1) {
					dist[e.v] = dist[u] + 1;
					q.push(edges[i].v);
				}
			}
		}
		return dist[sink] != -1;
	}

	int dfs(int u, int val) {
		if (u == sink) return val;
		for (; it[u] != adj[u].end(); it[u]++) {
			int &i = *it[u], path;
			Edge &e = edges[i];
			if (e.flow < e.cap && dist[e.v] == dist[u] + 1) {
				path = dfs(e.v, min(val, e.cap - e.flow));
				if (path > 0) {
					e.flow += path;
					edges[i ^ 1].flow -= path;
					return path;
				}
			}
		}
		return 0;
	}
	int dinic(int source, int sink) {
		this -> source = source;
		this -> sink = sink;
		int max_flow = 0;
		while (bfs()) {
			rep(i, n + start) it[i] = adj[i].begin();
			while (true) {
				int path = dfs(source, oo);
				if(path == 0) break;
				max_flow += path;
			}
		}
		return max_flow;
	}
};

int32_t main() {
	fastio;
	int n, m; cin >> n >> m;
	MaxFlow flow(n);
	rep(i, m) {
		int u, v, e;
		cin >> u >> v >> e;
		flow.add_edge(u, v, e);
		flow.add_edge(v, u, 0);
	}
	cout << flow.dinic(1, n) << endl;
	return 0;
}
