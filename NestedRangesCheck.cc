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

int32_t main() {
	fastio;
	int n; cin >> n;
	vector<pair<pii, int>> a(n);
	set<int> s;
	vii ans(n);

	rep(i, n) {
		cin >> a[i].ff.ff >> a[i].ff.ss;
		a[i].ss = i;
	}

	sort(all(a), [&](auto &x, auto &y) {
		if (x.ff.ss != y.ff.ss) {
			return x.ff.ss < y.ff.ss;
		}
		return x.ff.ff > y.ff.ff;
	});
	for (auto &x : a) {
		int st = x.ff.ff, id = x.ss;
		auto it = s.lower_bound(st);
		if (it != s.end()) ans[id].ff = 1;
		else ans[id].ff = 0;
		s.insert(st);
	}
	s.clear();
	sort(all(a), [&](auto &x, auto &y) {
		if (x.ff.ss != y.ff.ss) {
			return x.ff.ss > y.ff.ss;
		}
		return x.ff.ff < y.ff.ff;
	});
	for (auto &x : a) {
		int st = x.ff.ff, id = x.ss;
		auto it = s.lower_bound(-st);
		if (it != s.end()) ans[id].ss = 1;
		else ans[id].ss = 0;
		s.insert(-st);
	}
	for (auto x : ans) cout << x.ff << ' ';
	cout << endl;
	for (auto x : ans) cout << x.ss << ' ';
	return 0;
}
