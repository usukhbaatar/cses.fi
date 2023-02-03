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

int solve(int n, vi &mem) {
	if (n == 0) return 0;
	if (mem[n] > 0) return mem[n];
	int m = n, res = oo;
	while (m > 0) {
		int a = m % 10; m /= 10;
		if (a > 0) {
			minn(res, solve(n - a, mem) + 1);
		}
	}
	return mem[n] = res;
}

int32_t main() {
	fastio;
	int n; cin >> n;
	vi dp(n + 1, 0);
	cout << solve(n, dp) << endl;
	return 0;
}