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
	vector<pair<pii, int>> edges(m);
	rep(i, m) {
		cin >> edges[i].ff.ff >> edges[i].ff.ss >> edges[i].ss;
		edges[i].ss *= -1;
	}
	vi path(n + 1, oo);
	path[1] = 0;
	rep(i, n - 1) {
		for (auto &x : edges) {
			int &u = x.ff.ff, &v = x.ff.ss, &e = x.ss;
			if (path[u] != oo && path[u] + e < path[v]) {
				path[v] = path[u] + e;
			}
		}
	}
	cout << (path[n] == oo ? -1 : -path[n]) << endl;
	return 0;
}