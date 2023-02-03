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
	vi a(n + 1), pre(n + 1, 0);
	rep1(i, n) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	vvi mem(n + 1, vi(n + 1, 0));
	function<int(int, int)> solve = [&](int l, int r) {
		if (l == r) return a[l];
		if (mem[l][r]) return mem[l][r];
		int A = a[l] + (pre[r] - pre[l]) - solve(l + 1, r);
		int B = a[r] + (pre[r - 1] - pre[l - 1]) - solve(l, r - 1);
		return mem[l][r] = max(A, B);
	};
	cout << solve(1, n) << endl;
	return 0;
}