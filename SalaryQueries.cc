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

int N, bit[600001];

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
	vi a(n);
	vii v(n);
	v.pb({-oo, 0});
	rep(i, n) {
		cin >> a[i];
		v[i].ff = a[i];
		v[i].ss = i;
	}
	vector<pair<bool, pii>> b(q);
	rep(i, q) {
		char c; int x, y;
		cin >> c >> x >> y;
		b[i] = {c == '?', {x, y}};
		v.pb({y, -(i + 1)});
		if (c == '?') v.pb({x, i + n});
	}
	sort(all(v));
	int temp = v.size() - 1;
	rep1(i, temp) {
		if (v[i].ff != v[i - 1].ff)
			N++;
		if (v[i].ss >= n) {
			b[v[i].ss - n].ss.ff = N;
		} else if (v[i].ss >= 0) {
			a[v[i].ss] = N;
		} else {
			b[-(v[i].ss) - 1].ss.ss = N;
		}
	}
	rep(i, n) update(a[i], 1);
	for (auto [flag, z] : b) {
		if (flag) cout << query(z.ss) - query(z.ff - 1) << endl;
		else {
			update(a[z.ff - 1], -1);
			update(z.ss, 1);
			a[z.ff - 1] = z.ss;
		}
	}
	return 0;
}