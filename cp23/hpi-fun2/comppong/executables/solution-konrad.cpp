#include "bits/stdc++.h"
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int w, h;
	cin >> w >> h;
	vector a(h, vector<long long>(w));
	for (auto& x : a)
		for (auto& y : x)
			cin >> y;
	long long ans{0};
	for (int i = 0; i < h; i++) {
		vector<long long> b(w);
		for (int j = i; j < h; j++) {
			transform(begin(b), end(b), begin(a[j]), begin(b), plus<>());
			long long last{0};
			for (const auto& x : b)
				ans = max(ans, last = max(last + x, 0ll));
		}
	}
	cout << ans << '\n';
	return 0;
}
