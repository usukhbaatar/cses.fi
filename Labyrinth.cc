#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define heap priority_queue;
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
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<string> vs;

const int mod = 1e9 + 7;
const int oo ((((1LL << 62) - 1) << 1) + 1);
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int32_t main() {
	fastio;
	int n, m; cin >> n >> m;
	vs s(n);
	pii a, b;
	rep(i, n) {
		cin >> s[i];
		rep(j, m) {
			if (s[i][j] == 'A') {
				a = {i, j}; s[i][j] = '.';
			} else if (s[i][j] == 'B') {
				b = {i, j}; s[i][j] = '.';
			}
		}
	}
	vvii c(n, vii(m, {-1, -1}));
	queue<pii> q; q.push(a);
	c[a.ff][a.ss].ff = 0;
	while (!q.empty()) {
		int y, x; tie(y, x) = q.front(); q.pop();
		rep(i, 4) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy < 0 || yy >= n) continue;
			if (xx < 0 || xx >= m) continue;
			if (c[yy][xx].ff != -1) continue;
			if (s[yy][xx] != '.') continue;
			c[yy][xx] = { c[y][x].ff + 1, i };
			q.push({yy, xx});
		}
	}
	if (c[b.ff][b.ss].ff == -1) {
		cout << "NO\n";
		return 0;
	}
	string ans = "";
	string cmd = "URDL";
	cout << "YES\n" << c[b.ff][b.ss].ff << endl;
	while (b != a) {
		int i = c[b.ff][b.ss].ss;
		ans.pb(cmd[i]);
		b.ff -= dy[i];
		b.ss -= dx[i];
	}
	reverse(all(ans));
	cout << ans << endl;
	return 0;
}
