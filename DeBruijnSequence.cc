#include <bits/stdc++.h>
using namespace std;
 
string A = "01";
unordered_set<string> seen;
vector<int> edges;

void dfs(string node) {
	for (int i = 0; i < 2; i++) {
		string str = node + A[i];
		if (seen.find(str) == seen.end()) {
			seen.insert(str);
			dfs(str.substr(1));
			edges.push_back(i);
		}
	}
}

string deBruijn(int n) {
	string st = string(n - 1, '0');
	dfs(st);
	string res = "";
	for (int i = 0; i < (1 << n); i++)
		res += A[edges[i]];
	res += st;
	return res;
}
 
int main() {
	int n; cin >> n;
	cout << deBruijn(n);
	return 0;
}