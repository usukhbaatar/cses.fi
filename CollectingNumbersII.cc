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

signed main() {
	fastio;
	int n, m, ans = 0, p = oo;
	cin >> n >> m;
	vi a(n + 2, 0), b(n + 2, 0);
	rep1(i, n) { cin >> a[i]; b[a[i]] = i; }
	rep1(i, n) { ans += b[i] < p; p = b[i]; }
	a[n + 1] = n + 1; b[n + 1] = n + 1;
	while (m--) {
		int idx, idy, x, y;
		cin >> idx >> idy;
		if (idx > idy) swap(idx, idy);
		x = a[idx]; y = a[idy];
		if (idx < b[x - 1] && b[x - 1] < idy) ans--;
		if (idx < b[x + 1] && b[x + 1] < idy) ans++;
		if (idx < b[y - 1] && b[y - 1] < idy) ans++;
		if (idx < b[y + 1] && b[y + 1] < idy) ans--;
		if (x + 1 == y) ans++;
		if (x - 1 == y) ans--;
		swap(a[idx], a[idy]);
		swap(b[a[idx]], b[a[idy]]);
		cout << ans << endl;
	}
	return 0;
}