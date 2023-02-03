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
	int n, x; cin >> n >> x;
	vii a(n);
	rep(i, n) {
		cin >> a[i].ff;
		a[i].ss = i + 1;
	}
	sort(all(a));
	rep(i, n) {
		int l = i + 1, r = n - 1;
		while (l < r) {
			if (a[l].ff + a[r].ff > x - a[i].ff) r--;
			else if (a[l].ff + a[r].ff < x - a[i].ff) l++;
			else {
				cout << a[i].ss << ' ' << a[l].ss << ' ' << a[r].ss << endl;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}