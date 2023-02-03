#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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
template <class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int oo ((((1LL << 62) - 1) << 1) + 1);
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

pii meta(int i) { return {(i << 1) + 1, (i + 1) << 1}; }
tuple<int, int, int> meta(int i, int l, int r) {
	pii m = meta(i); return { m.ff, m.ss, (l + r) / 2 };
}
void merge(int, int, int);
pair<pii, int> merge(pair<pii, int>, pair<pii, int>);

vi a, val[4];
void init(int n) {
	rep(i, 4) val[i].resize((n + 1) << 2, 0);
	a.resize(n + 1, 0);
}

void build(int i, int tl, int tr) {
	if (tl == tr) {
		val[0][i] = max(0LL, a[tl]);
		val[1][i] = max(0LL, a[tl]);
		val[2][i] = max(0LL, a[tl]);
		val[3][i] = a[tl];
		return;
	}
	auto [x, y, tm] = meta(i, tl, tr);
	build(x, tl, tm);
	build(y, tm + 1, tr);
	merge(i, x, y);
}

void update(int i, int tl, int tr, int k, int t) {
	if (tl == tr) {
		val[0][i] = max(0LL, t);
		val[1][i] = max(0LL, t);
		val[2][i] = max(0LL, t);
		val[3][i] = t;
		return;
	}
	auto [x, y, tm] = meta(i, tl,  tr);
	if (k <= tm) update(x, tl, tm, k, t);
	else update(y, tm + 1, tr, k, t);
	merge(i, x, y);
}

void merge(int i, int x, int y) {
	val[0][i] = max(0LL, max(val[0][x], val[3][x] + val[0][y]));
	val[1][i] = max(0LL, max(val[1][x] + val[3][y], val[1][y]));
	val[2][i] = max(val[0][y] + val[1][x], max(val[2][x], val[2][y]));
	val[3][i] = val[3][x] + val[3][y];
}

int32_t main() {
	fastio;
	int n, q; cin >> n >> q;
	init(n);
	rep(i, n) cin >> a[i];
	build(0, 0, n - 1);
	rep(i, q) {
		int k, x; cin >> k >> x;
		update(0, 0, n - 1, k - 1, x);
		cout << val[2][0] << endl;
	}
	return 0;
}