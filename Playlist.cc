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

signed main() {
	fastio;
	int n, x, ans = 0, l = 0;
	set<int> s; vi a;
	cin >> n;
	rep(i, n) {
		cin >> x; a.pb(x);
		auto it = s.find(x);
		if (it == s.end()) s.insert(x);
		else {
			while (l <= i && a[l] != x) {
				s.erase(a[l]); l++;
			}
			l++;
		}
		maxx(ans, (int)s.size());
	}
	cout << ans << endl;
	return 0;
}