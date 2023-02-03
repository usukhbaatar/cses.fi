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
	vs b(n);
	rep(i, n) cin >> b[i];
	vvi a(n + 1, vi(n + 1, 0));
	auto update = [&](int i, int j, int z) -> void {
		for (int ii = i; ii <= n; ii += (ii & -ii)) {
			for (int jj = j; jj <= n; jj += (jj & -jj)) {
				a[ii][jj] += z;
			}
		}
	};
	auto query = [&](int i, int j) -> int {
		int ret = 0;
		for (int ii = i; ii > 0; ii -= (ii & -ii)) {
			for (int jj = j; jj > 0; jj -= (jj & -jj)) {
				ret += a[ii][jj];
			}
		}
		return ret;
	};
	auto rect = [&](int y1, int x1, int y2, int x2) {
		return query(y2, x2) - query(y1, x2) - query(y2, x1) + query(y1, x1);
	};
	rep(i, n) rep(j, n) {
		if (b[i][j] == '*') {
			update(i + 1, j + 1, 1);
		}
	}
	while (q--) {
		int c; cin >> c;
		if (c == 1) {
			int y, x; cin >> y >> x;
			if (b[y - 1][x - 1] == '*') {
				update(y, x, -1);
				b[y - 1][x - 1] = '.';
			} else {
				update(y, x, 1);
				b[y - 1][x - 1] = '*';
			}
		} else {
			int y1, x1; cin >> y1 >> x1;
			int y2, x2; cin >> y2 >> x2;
			y1--; x1--;
			cout << rect(y1, x1, y2, x2) << endl;
		}
	}
	return 0;
}