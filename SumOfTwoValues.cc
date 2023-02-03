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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int mod = 1e9 + 7;
const int oo ((((1LL << 62) - 1) << 1) + 1);

signed main() {
	fastio;
	int n, x;
	cin >> n >> x;
	vii a(n);
	rep(i, n) { cin >> a[i].ff; a[i].ss = i + 1; }
	sort(all(a));
	int i = 0, j = n - 1;
	while (i < j) {
		if (a[i].ff + a[j].ff < x) i++;
		else if (a[i].ff + a[j].ff > x ) j--; 
		else {
			cout << a[i].ss << ' ' << a[j].ss << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}