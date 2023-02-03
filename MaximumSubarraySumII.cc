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
	int n, a, b; cin >> n >> a >> b;
	vi pre(n + 1);
	pre[0] = 0;
	rep1(i, n) {
		int x; cin >> x;
		pre[i] = pre[i - 1] + x;
	}
	multiset<int> s;
	int ans = -oo;
	for(int i = a; i <= n; i++) {
		if (i > b) s.erase(s.find(pre[i - b - 1]));
		s.insert(pre[i - a]);
		maxx(ans, pre[i] - *(s.begin()));
	}
	cout << ans << endl;
	return 0;
}