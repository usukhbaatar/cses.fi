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
	vii a(n);
	rep(i, n) {
		cin >> a[i].ff;
		a[i].ss = -(i + 1);
	}
	sort(all(a));
	set<int> s;
	vi ans(n, 0);
	for (auto x : a) {
		int id = -x.ss;
		auto it = s.lower_bound(x.ss);
		if (it != s.end()) {
			ans[id - 1] = *it;
		}
		s.insert(x.ss);
	}
	for (int x : ans) {
		cout << -x << ' ';
	}
	cout << endl;
	return 0;
}