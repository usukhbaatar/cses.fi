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

int solve(int n, int m, vvi &mem) {
	if (n == m) return 0;
	if (min(n, m) == 1) return max(n, m) - 1;
	if (mem[n][m]) return mem[n][m];
	int ans = oo;
	rep1(i, n / 2) {
		minn(ans, solve(i, m, mem) + solve(n - i, m, mem) + 1);
	}
	rep1(j, m / 2) {
		minn(ans, solve(n, j, mem) + solve(n, m - j, mem) + 1);
	}
	return mem[n][m] = ans;
} 

int32_t main() {
	fastio;
	int n, m; cin >> n >> m;
	vvi dp(n + 1, vi(m + 1, 0));
	cout << solve(n, m, dp) << endl;	
	return 0;
}