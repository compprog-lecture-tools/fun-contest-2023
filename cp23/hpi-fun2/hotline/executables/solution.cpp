#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define all(a) (a).begin(),(a).end()
#define trav(e,v) for(auto& e : (v))
using vi = vector<int>;

bool dd(int k) {
	vector<bool> o(10, false);
	while (k > 0) {
		int digit = k % 10;
		if (o[digit]) return false;
		o[digit] = true;
		k = (k - digit) / 10;
	}
	return true;
}

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int l, r; cin >> l >> r;
	rep(i, l, r+1)
		if (dd(i)) {
			cout << i << endl;
			return 0;
		}
	cout << -1 << endl;
	return 0;
}
