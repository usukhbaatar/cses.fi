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
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<vi> dp(n + 1, vi(n + 1, 0));
	dp[1][1] = s[0][0] == '.';
	rep1(i, n) rep1(j, n) {
		if (s[i - 1][j - 1] == '*') continue;
		dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
		dp[i][j] %= mod;
	}
	cout << dp[n][n] << endl;
	return 0;
}