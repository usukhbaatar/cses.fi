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

int N;
vi bit;

void update(int i, int x = 1) {
	while (i <= N) {
		bit[i] += x;
		i += (i & -i);
	}
}

int query(int i) {
	int ret = 0;
	while (i > 0) {
		ret += bit[i];
		i -= (i & -i);
	}
	return ret;
}

int32_t main() {
	fastio;
	int n, q; cin >> n >> q;
	vi a(n + 1); vii v(n + 1);
	v[0] = {-oo, 0};
	rep1(i, n) {
		cin >> a[i];
		v[i] = {a[i], i};
	}
	sort(all(v));
	int t = 0;
	rep1(i, n) {
		if (v[i].ff != v[i - 1].ff) t++;
		a[v[i].ss] = t;
	}
	N = n;
	bit.resize(n + 1);
	vi pre(n + 1, -1), pos(n + 1, -1);
	rep1(i, n) {
		pre[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	vvii qry(n + 1);
	vi ans(q);
	rep(i, q) {
		int l, r; cin >> l >> r;
		qry[r].pb({l, i});
	}
	rep1(i, n) {
		if (pre[i] > 0) update(pre[i], -1);
		update(i, 1);
		int s = query(i);
		for (auto &q : qry[i]) {
			ans[q.ss] = s - query(q.ff - 1);
		}
	}
	rep(i, q) {
		cout << ans[i] << endl;
	}
	return 0;
}