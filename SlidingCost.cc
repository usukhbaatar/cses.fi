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
	int n, k; cin >> n >> k;
	vi a(n), b(k);
	rep(i, n) cin >> a[i];
	rep(i, k) b[i] = a[i];
	sort(all(b));
	multiset<int> p, q;
	int A = 0, B = 0;
	rep(i, k) {
		if (i < (k + 1) / 2) {
			A += b[i];
			p.insert(b[i]);
		} else {
			B += b[i];
			q.insert(b[i]);
		}
	}
	int m = *(p.rbegin());
	auto calc = [&](int m) -> int {
		return (p.size() * m - A) + (B - q.size() * m);
	};
	cout << calc(m);
	rep(i, n - k) {
		if (a[i] <= m) {
			A -= a[i];
			p.erase(p.find(a[i]));
		} else {
			B -= a[i];
			q.erase(q.find(a[i]));
		}
		if (a[i + k] < m) {
			A += a[i + k];
			p.insert(a[i + k]);
		} else {
			B += a[i + k];
			q.insert(a[i + k]);
		}
		if (p.size() < q.size() + k % 2) {
			A += *(q.begin());
			B -= *(q.begin());
			p.insert(*(q.begin()));
			q.erase(q.begin());
		} else if (p.size() > q.size() + k % 2) {
			auto it = p.end(); it--;
			A -= *it;
			B += *it;
			q.insert(*it);
			p.erase(it);
		}
		m = *(p.rbegin());
		cout << ' ' << calc(m);
	}
	cout << endl;
	return 0;
}