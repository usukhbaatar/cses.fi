#include <string>
#include <iostream>
using namespace std;
string b[8];
int p[8];

bool can(int y, int x) {
	if (b[y][x] == '*') return 0;
	for (int i = 0; i < y; i++) {
		int yy = i, xx = p[i];
		if (x == xx || abs(x - xx) == abs(y - yy))
			return 0;
	}
	return 1;
}

int count(int y, int x) {
	p[y] = x;
	if (y == 7) return 1;
	int ret = 0;
	for (int i = 0; i < 8; i++) {
		if (can(y + 1, i)) {
			ret += count(y + 1, i);
		}
	}
	return ret;
}

int main() {
	for (int i = 0; i < 8; i++) {
		cin >> b[i];
	}
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		if (b[0][i] != '*') {
			ans += count(0, i);
		}
	}
	cout << ans << endl;
	return 0;
}
