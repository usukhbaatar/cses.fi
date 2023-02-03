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
	string a, b; cin >> a >> b;
	int n = a.size(), m = b.size();
	vector<vi> dp(n + 1, vi(m + 1, 0));
	a = '#' + a; b = '#' + b;
	rep1(i, n) dp[i][0] = i;
	rep1(j, m) dp[0][j] = j;
	rep1(i, n) rep1(j, m) {
		dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
		minn(dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
	}
	cout << dp[n][m] << endl;
	return 0;
}