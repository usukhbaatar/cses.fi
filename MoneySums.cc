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
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const int mod = 1e9 + 7;
const int oo ((((1LL << 62) - 1) << 1) + 1);

int32_t main() {
	fastio;
	int n, s = 0; cin >> n;
	vi a(n);
	rep(i, n) {
		cin >> a[i];
		s += a[i];
	}
	vector<bool> dp(s + 1, 0);
	int x = 0; dp[0] = 1;
	rep(i, n) {
		for (int j = x; j >= 0; j--) {
			dp[j + a[i]] = dp[j + a[i]] | dp[j];
		}
		x += a[i];
	}
	int ans = 0;
	rep1(i, s) ans += dp[i];
	cout << ans << endl;
	rep1(i, s) if (dp[i]) cout << i << ' ';
	cout << endl;
	return 0;
}