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

const int N = 1e6;
vi a, b;

void build() {
	a.resize(N + 1);
	b.resize(N + 1);
	a[1] = b[1] = 1;
	for (int i = 2; i <= N; i++) {
		a[i] = (2 * a[i - 1] + b[i - 1]) % mod;
		b[i] = (4 * b[i - 1] + a[i - 1]) % mod;
	}
}

int32_t main() {
	fastio;
	build();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << (a[n] + b[n]) % mod << endl;
	}
	return 0;
}