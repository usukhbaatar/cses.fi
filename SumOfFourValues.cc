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
	vi a(n);
	rep(i, n) {
		cin >> a[i];
	}
	vector<pair<int, pii>> b;
	rep(i, n) {
		for (int j = i + 1; j < n; j++) {
			b.pb({a[i] + a[j], {i + 1, j + 1}});
		}
	}
	sort(all(b));
	int l = 0, r = b.size() - 1;
	while (l < r) {
		int s = b[l].ff + b[r].ff;
		if (s > x) r--;
		else if (s < x) l++;
		else {
			set<int> s;
			s.insert(b[l].ss.ff);
			s.insert(b[l].ss.ss);
			s.insert(b[r].ss.ff);
			s.insert(b[r].ss.ss);
			if (s.size() == 4) {
				for (auto it = s.begin(); it != s.end(); it++) {
					cout << *it << ' ';
				}
				cout << endl;
				return 0;
			} else {
				r--;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}