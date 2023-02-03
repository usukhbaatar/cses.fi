#include <set>
#include <iostream>
using namespace std;

int main() {
	set<int> s;
	int n, a; cin >> n;
	while (n--) {
		cin >> a;
		s.insert(a);
	}
	cout << s.size() << endl;
	return 0;
}
