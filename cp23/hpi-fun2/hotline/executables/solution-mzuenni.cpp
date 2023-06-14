#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()

using ll = long long;
using ld = long double;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll l, r;
	cin >> l >> r;
	for (ll i = l; i <= r; i++) {
		string c = to_string(i);
		sort(all(c));
		bool ok = true;
		for (ll j = 0; j + 1 < sz(c) && ok; j++)
			ok = c[j] != c[j+1];
		if (ok) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
