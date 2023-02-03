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
const int kx[] = {-2, -2, -1, -1,  1,  1,  2,  2};
const int ky[] = {-1,  1, -2,  2, -2,  2, -1,  1};

int32_t main() {
	fastio;
	int sx, sy; cin >> sx >> sy;
	vvi board(9, vi(9, 0));
	auto inside = [&](int x, int y) -> bool {
		return x >= 1 && x <= 8 && y >= 1 && y <= 8;
	};
	auto degree = [&](int x, int y) -> int {
		int ret = 0;
		rep(i, 8) {
			int xx = x + kx[i];
			int yy = y + ky[i];
			if (inside(xx, yy)) {
				if (board[xx][yy] == 0)
					ret++;
			}
		}
		return ret;
	};
	function<bool(int, int, int)> rec = [&](int s, int x, int y) {
		board[x][y] = s;
		if (s == 64) return 1;
		vector<pair<int, pii>> next;
		rep(i, 8) {
			int xx = x + kx[i];
			int yy = y + ky[i];
			if (!inside(xx, yy)) continue;
			if (board[xx][yy] != 0) continue;
			int dd = degree(xx, yy);
			next.pb({dd, {xx, yy}});
		}
		sort(all(next));
		for (auto &n : next) {
			if (rec(s + 1, n.ss.ff, n.ss.ss)) return 1;
		}
		board[x][y] = 0;
		return 0;
	};
	if (!rec(1, sx, sy)) return 0;
	rep1(i, 8) {
		rep1(j, 8) {
			cout << board[j][i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
