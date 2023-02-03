#include <cmath>
#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        int c = 1;
        long long p = 9;
        while (n - p > 0) {
        	n -= p;
        	p = p * 10 / c * (c + 1);
        	c++;
        }
        n--;
        long long x = n / c;
        long long y = n % c;
        long long ans = 1;
        for (int i = 0; i < c - 1; i++) {
        	ans *= 10;
        }
        ans += x;
        string s = to_string(ans);
        cout<<s[y]<<endl;
    }
}
