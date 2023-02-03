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
	int n, k; cin >> n >> k;
	vi a(n);
	rep(i, n) cin >> a[i];
	map<int, int> m;
	int l = 0, sz = 0, ans = 0;
	rep(i, n) {
		auto it = m.find(a[i]);
		if (it == m.end()) {
			m[a[i]] = 1;
			sz++;
		} else {
			it -> second++;
		}
		while (sz > k) {
			auto it1 = m.find(a[l]);
			if (it1 -> second == 1) {
				m.erase(it1);
				sz--;
			} else {
				it1 -> second--;
			}
			l++;
		}
		ans += (i + 1 - l);
	}
	cout << ans << endl;
	return 0;
}
