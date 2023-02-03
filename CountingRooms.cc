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
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const int mod = 1e9 + 7;
const int oo ((((1LL << 62) - 1) << 1) + 1);

int32_t main() {
	fastio;
	int n, m; cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<vector<bool>> vis(n, vector<bool>(m, 0));
	int ans = 0;
	function<void(int, int)> fill = [&](int i, int j) {
		if (i < 0 || j < 0 || i >= n || j >= m) return;
		if (s[i][j] != '.' || vis[i][j]) return;
		vis[i][j] = 1;
		fill(i - 1, j); fill(i, j + 1);
		fill(i + 1, j); fill(i, j - 1);
	};
	rep(i, n) rep(j, m) {
		if (!vis[i][j] && s[i][j] == '.') {
			ans++; fill(i, j);
		}
	}
	cout << ans << endl;
	return 0;
}