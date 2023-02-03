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
	int n, x; cin >> n >> x;
	vi a(n);
	rep(i, n) cin >> a[i];
	int l = 0, s = 0, ans = 0;
	rep(i, n) {
		s += a[i];
		while (s > x) {
			s -= a[l]; l++;
		}
		if (s == x) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}