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

int N;
vi bit;

void update(int i, int x = 1) {
	while (i <= N) {
		bit[i] += x;
		i += (i & -i);
	}
}

int query(int i) {
	int ret = 0;
	while (i > 0) {
		ret += bit[i];
		i -= (i & -i);
	}
	return ret;
}

int32_t main() {
	fastio;
	int n, q; cin >> n >> q;
	vi a(n + 1);
	rep1(i, n) cin >> a[i];
	N = n + 10; bit.resize(N);
	while (q--) {
		int c; cin >> c;
		if (c == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			update(l, x);
			update(r + 1, -x);
		} else {
			int k; cin >> k;
			cout << a[k] + query(k) << endl;
		}
	}
	return 0;
}