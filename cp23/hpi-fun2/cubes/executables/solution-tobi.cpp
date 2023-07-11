#include <bits/stdc++.h>

#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    vvi points(n, vi(3));
    rep(i, 0, n) rep(j, 0, 3) cin >> points[i][j];
    sort(all(points));
    ll ans = 6 * n;
    for (auto p: points)
        rep(i, 0, 3) {
            p[i]++;
            ans -= 2 * binary_search(all(points), p);
            p[i]--;
        }
    cout << ans << endl;

    return 0;
}
