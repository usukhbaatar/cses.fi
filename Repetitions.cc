#include <string>
#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int mx = 1, c = 1;
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] == s[i - 1]) c++;
		else c = 1;
		mx = max(mx, c);
	}
	cout << mx << endl;
	return 0;
}