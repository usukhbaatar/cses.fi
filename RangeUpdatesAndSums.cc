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
int merge(int, int);

vi a, val;
vector<pair<bool, int>> lazy;
void init(int n) {
	val.resize((n + 1) << 2, 0);
	a.resize(n + 1, 0);
	lazy.resize((n + 1) << 2, {0, 0});
}

void build(int i, int tl, int tr) {
	if (tl == tr) { val[i] = a[tl]; return; }
	auto [x, y, tm] = meta(i, tl, tr);
	build(x, tl, tm);
	build(y, tm + 1, tr);
	merge(i, x, y);
}

void propagate(int i, int tl, int tr) {
	if (!lazy[i].ff && lazy[i].ss == 0) return;
	auto [x, y, tm] = meta(i, tl, tr);
	if (lazy[i].ff) {
		lazy[x].ff = 1;
		lazy[x].ss = lazy[i].ss;
		val[x] = (tm - tl + 1) * lazy[i].ss;
		lazy[y].ff = 1;
		lazy[y].ss = lazy[i].ss;
		val[y] = (tr - tm) * lazy[i].ss;
	} else {
		lazy[x].ss += lazy[i].ss;
		val[x] += (tm - tl + 1) * lazy[i].ss;
		lazy[y].ss += lazy[i].ss;
		val[y] += (tr - tm) * lazy[i].ss;
	}
	merge(i, x, y);
	lazy[i] = {0, 0};
}

void update(int i, int tl, int tr, int l, int r, int v, bool type) {
	if (tl == l && r == tr) {
		if (l == r) {
			lazy[i] = {0, 0};
			if (type) val[i] = v;
			else val[i] += v;
			return;
		}
		int temp = val[i];
		propagate(i, tl, tr);
		int temp1 = val[i];
		if (temp != temp1) {
			exit(0);
		}
		lazy[i] = {type, v};
		if (type) val[i] = (tr - tl + 1) * v;
		else val[i] += (tr - tl + 1) * v;
		return;
	}
	auto [x, y, tm] = meta(i, tl,  tr);
	if (r <= tm) update(x, tl, tm, l, r, v, type);
	else if (tm < l) update(y, tm + 1, tr, l, r, v, type);
	else {
		update(x, tl, tm, l, tm, v, type);
		update(y, tm + 1, tr, tm + 1, r, v, type);
	}
	merge(i, x, y);
}

int query(int i, int tl, int tr, int l, int r) {
	if (tl == l && r == tr) return val[i];
	propagate(i, tl, tr);
	auto [x, y, tm] = meta(i, tl, tr);
	if (r <= tm) return query(x, tl, tm, l, r);
	else if (tm < l) return query(y, tm + 1, tr, l, r);
	return merge(query(x, tl, tm, l, tm), query(y, tm + 1, tr, tm + 1, r));
}

void merge(int i, int x, int y) {
	val[i] = val[x] + val[y];
}

int merge(int x, int y) {
	return x + y;
}

int32_t main() {
	fastio;
	int n, q; cin >> n >> q;
	init(n);
	rep(i, n) cin >> a[i];
	build(0, 0, n - 1);
	rep(i, q) {
		int c, l, r;
		cin >> c >> l >> r;
		if (c == 3) {
			cout << query(0, 0, n - 1, l - 1, r - 1) << endl; 
		} else {
			int x; cin >> x;
			update(0, 0, n - 1, l - 1, r - 1, x, c == 2);
		}
	}
	return 0;
}