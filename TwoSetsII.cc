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
	int n; cin >> n;
	int s = n * (n + 1) / 2, x = 0;
	if (s & 1) {
		cout << 0 << endl;
		return 0;
	}
	s >>= 1;
	vi dp(s + 1, 0);
	dp[0] = 1;
	rep1(i, n) {
		for (int j = min(x, s - i); j >= 0; j--) {
			dp[j + i] += dp[j];
			dp[j + i] %= (mod << 1);
		}
		x += i;
	}
	cout << dp[s] / 2 << endl;
	return 0;
}