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

pii meta(int i) { return {(i << 1) + 1, (i + 1) << 1}; }
tuple<int, int, int> meta(int i, int l, int r) {
	pii m = meta(i); return { m.ff, m.ss, (l + r) / 2 };
}
void merge(int, int, int);
int merge(int, int);

vi a, val;
void init(int n) {
	val.resize((n + 1) << 2);
	a.resize(n + 1, 0);
}

void build(int i, int tl, int tr) {
	if (tl == tr) { val[i] = a[tl]; return; }
	auto [x, y, tm] = meta(i, tl, tr);
	build(x, tl, tm);
	build(y, tm + 1, tr);
	merge(i, x, y);
}

void update(int i, int tl, int tr, int k, int t) {
	if (tl == tr) { val[i] = t; return; }
	auto [x, y, tm] = meta(i, tl,  tr);
	if (k <= tm) update(x, tl, tm, k, t);
	else update(y, tm + 1, tr, k, t);
	merge(i, x, y);
}

int query(int i, int tl, int tr, int l, int r) {
	if (tl == l && r == tr) return val[i];
	auto [x, y, tm] = meta(i, tl, tr);
	if (r <= tm) return query(x, tl, tm, l, r);
	else if (tm + 1 <= l) return query(y, tm + 1, tr, l, r);
	return merge(query(x, tl, tm, l, tm), query(y, tm + 1, tr, tm + 1, r));
}

void merge(int i, int x, int y) {
	val[i] = min(val[x], val[y]);
}

int merge(int x, int y) {
	return min(x, y);
}

int32_t main() {
	fastio;
	int n, q; cin >> n >> q;
	init(n);
	rep1(i, n) cin >> a[i];
	build(0, 1, n);
	while (q--) {
		int c; cin >> c;
		if (c == 1) {
			int k, x; cin >> k >> x;
			update(0, 1, n, k, x);
		} else {
			int l, r; cin >> l >> r;
			cout << query(0, 1, n, l, r) << endl;
		}
	}
	return 0;
}