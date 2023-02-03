#include <vector>
#include <iostream>
using namespace std;

void print(vector<int> &a) {
	cout << a.size() << endl;
	for (int i : a) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
	int n; cin >> n;
	long long s = 1ll * n * (n + 1) / 2;
	if (s & 1) {
		cout << "NO\n";
		return 0;
	}
	s /= 2;
	vector<int> a, b;
	for (int i = n; i >= 1; i--) {
		if (s >= i) {
			a.push_back(i);
			s -= i;
		} else {
			b.push_back(i);
		}
	}
	cout << "YES\n";
	print(a);
	print(b);
	return 0;
}