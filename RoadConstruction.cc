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

struct DSU {
	vi p, w;
	int groups;
	DSU(int n, int start = 0) {
		groups = n;
		p.resize(n + start, -1);
		w.resize(n + start, 1);
	}
	bool is_root(int x) {
		return p[x] == -1;
	}
	int find(int x) {
		if (is_root(x)) return x;
		return p[x] = find(p[x]);
	}
	int merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return w[x];
		if (w[y] > w[x]) swap(x, y);
		w[x] += w[y]; w[y] = 0;
		p[y] = x; groups--;
		return w[x];
	}
	int size() {
		return groups;
	}
};

int32_t main() {
	fastio;
	int n, m, ans = 0; cin >> n >> m;
	DSU dsu(n, 1);
	rep(i, m) {
		int u, v; cin >> u >> v;
		maxx(ans, dsu.merge(u, v));
		cout << dsu.size() << ' ' << ans << endl;
	}
	return 0;
}