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

vi ciphers(int n) {
	vi c;
	for (; n > 0; n /= 10) c.pb(n % 10);
	c.pb(0);
	reverse(all(c));
	return c;
}

int count(int a) {
	if (a < 0) return 0;
	vi c = ciphers(a);
	int n = c.size() - 1;
	vector<vvi> dp(n + 1, vvi(10, vi(2, 0)));
	rep1(i, n) dp[i][0][0] = 1;
	dp[0][0][1] = 1;
	rep1(i, n) rep(j, 10) {
		rep(k, 10) {
			if (k == j) continue;
			dp[i][j][0] += dp[i - 1][k][0];
		}
		if (j < c[i] && j != c[i - 1])
			dp[i][j][0] += dp[i - 1][c[i - 1]][1];
		if (c[i - 1] != c[i])
			dp[i][c[i]][1] = dp[i - 1][c[i - 1]][1];
	}
	int ans = 0;
	rep(i, 10) ans += (dp[n][i][0] + dp[n][i][1]);
	return ans;
}

int32_t main() {
	fastio;
	int a, b; cin >> a >> b;
	cout << count(b) - count(a - 1) << endl;	
	return 0;
}