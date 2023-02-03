#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	string s;
	cin >> s;
	vector<string> ans;
	sort(s.begin(), s.end());
	do {
		ans.push_back(s);
	} while(next_permutation(s.begin(), s.end()));
	cout << ans.size() << endl;
	for (string i : ans) {
		cout << i << endl;
	}
	return 0;
}