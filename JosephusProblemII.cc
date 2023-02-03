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

const int maxn = 200001;
int sum[maxn << 2];

void build(int id, int L, int R) {
	sum[id] = R - L + 1;
	if (L == R) return;
	int M = L + (R - L) / 2;
	int x = (id << 1) + 1, y = x + 1;
	build(x, L, M);
	build(y, M + 1, R);
}

int query_and_update(int id, int L, int R, int k) {
	sum[id]--;
	if (L == R) {
		return L + 1;
	}
	int M = L + (R - L) / 2;
	int x = (id << 1) + 1, y = x + 1;
	if (sum[x] >= k)
		return query_and_update(x, L, M, k);
	return query_and_update(y, M + 1, R, k - sum[x]);
}

int32_t main() {
	fastio;
	int N, n, k, m; cin >> n >> k;
	build(0, 0, n - 1);
	m = (k) % n + 1;
	N = n;
	rep(i, n) {
		cout << query_and_update(0, 0, n - 1, m) << ' ';
		m = N > 1 ? (m - 1 + k) % --N + 1 : 1;
	}
	return 0;
}