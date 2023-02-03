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
	int n, k; cin >> n >> k;
	vi a(n);
	int l = 0, r = 2e14 + 1;
	rep(i, n) {
		cin >> a[i];
		maxx(l, a[i] - 1);
	}
	while (l + 1 < r) {
		int m = (l + r) / 2;
		int cnt = 0, s = 0;
		rep(i, n) {
			if (s + a[i] > m) {
				cnt++;
				s = a[i];
			} else {
				s += a[i];
			}
		}
		if (cnt < k) r = m;
		else l = m;
	}
	cout << r << endl;
	return 0;
}