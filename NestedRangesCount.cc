#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
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
typedef vector<pii> vii;

const int mod = 1e9 + 7;
const int oo ((((1LL << 62) - 1) << 1) + 1);

int N, bit[400001];

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
	int n; cin >> n;
	vector<pair<pii, int>> a(n);
	set<int> s;
	map<int, int> m;
	vii ans(n);

	rep(i, n) {
		cin >> a[i].ff.ff >> a[i].ff.ss;
		a[i].ss = i;
		s.insert(a[i].ff.ff);
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		N++; m[*it] = N;
	}

	sort(all(a), [](auto &x, auto &y) {
		if (x.ff.ss != y.ff.ss) {
			return x.ff.ss < y.ff.ss;
		}
		return x.ff.ff > y.ff.ff;
	});
	int cnt = 0;
	for (auto x : a) {
		int st = x.ff.ff, id = x.ss;
		ans[id].ff = cnt - query(m[st] - 1);
		update(m[st]);
		cnt++;
	}

	sort(all(a), [](auto &x, auto &y) {
		if (x.ff.ss != y.ff.ss) {
			return x.ff.ss > y.ff.ss;
		}
		return x.ff.ff < y.ff.ff;
	});
	memset(bit, 0, sizeof(bit));
	for (auto x : a) {
		int st = x.ff.ff, id = x.ss;
		ans[id].ss = query(m[st]);
		update(m[st]);
	}
	for (auto x : ans) cout << x.ff << ' ';
	cout << endl;
	for (auto x : ans) cout << x.ss << ' ';
	return 0;
}