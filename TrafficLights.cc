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
	int N, n, x;
	cin >> N >> n;
	vii a(n + 2);
	vi prev(n + 2), next(n + 2), pos(n + 2), ans(n + 2, 0);
	rep1(i, n) {
		cin >> x;
		a[i] = {x, i};
		pos[i] = x;
	}
	pos[0] = 0; pos[n + 1] = N;
	a[0] = {0, 0};
	a[n + 1] = {N, n + 1};
	sort(all(a));
	rep(i, n + 2) maxx(ans[n], a[i + 1].ff - a[i].ff);
	next[0] = a[1].ss;
	rep1(i, n) {
		prev[a[i].ss] = a[i - 1].ss;
		next[a[i].ss] = a[i + 1].ss;
	}
	prev[n + 1] = a[n].ss;
	for (int i = n; i >= 1; i--) {
		int x = prev[i];
		int y = next[i];
		ans[i - 1] = max(ans[i], pos[y] - pos[x]);
		next[x] = y;
		prev[y] = x;
	}
	rep1(i, n) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}