#include <bits/stdc++.h>

#define rep(a, b)   for(ll a = 0; a < (b); ++a)

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // TODO: Solution
    ll n; cin >> n;
    rep(_, 3 * n / 2) { ll a, b; cin >> a >> b; }
    cout << n / 2 << endl;

    return 0;
}