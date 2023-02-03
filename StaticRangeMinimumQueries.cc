#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define heap priority_queue
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
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;

const int mod = 1e9 + 7;
const int oo ((((1LL << 62) - 1) << 1) + 1);
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int32_t main() {
	fastio;
	int n, q; cin >> n >> q;
	int k = ceil(log2(n));
	vvi a(n + 1, vi(k + 1));
	rep1(i, n) cin >> a[i][0];
	rep1(j, k) {
		rep1(i, n) if (i + (1 << j) - 1 <= n) {
			a[i][j] = min(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
		}
	}
	while (q--) {
		int l, r; cin >> l >> r;
		int d = floor(log2(r - l + 1));
		r = r - (1 << d) + 1;
		cout << min(a[l][d], a[r][d]) << endl;
	}
	return 0;
}