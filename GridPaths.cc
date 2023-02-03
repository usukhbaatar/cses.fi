#include <string>
#include <iostream>
using namespace std;

int ans = 0;
string cmd;
int vis[9][9];

void go(int s, int y, int x) {
	if (vis[y][x]) return;
	if (y == 7 && x == 1) {
		if (s == 48) ans++;
		return;
	}
	int a = vis[y][x - 1] + vis[y][x + 1];
	int b = vis[y - 1][x] + vis[y + 1][x];
	if (a + b == 2 && a * b == 0) return;
	vis[y][x] = 1;
	if (cmd[s] == 'R') {
		go(s + 1, y, x + 1);
	} else if (cmd[s] == 'L') {
		go(s + 1, y, x - 1);
	} else if (cmd[s] == 'U') {
		go(s + 1, y - 1, x);
	} else if (cmd[s] == 'D') {
		go(s + 1, y + 1, x);
	} else {
		go(s + 1, y, x + 1);
		go(s + 1, y, x - 1);
		go(s + 1, y - 1, x);
		go(s + 1, y + 1, x);
	}
	vis[y][x] = 0;
}

int main() {
	for (int i = 0; i <= 8; i++) {
		vis[0][i] = 1;
		vis[i][0] = 1;
		vis[i][8] = 1;
		vis[8][i] = 1;
	}
	cin >> cmd;
	go(0, 1, 1);
	cout << ans << endl;
	return 0;
}
