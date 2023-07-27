#include <bits/stdc++.h>

#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, l; cin >> n >> l;
    vi m(n);
    rep(i, 0, n) cin >> m[i];
    vector<vi> adj(n);
    rep(i, 1, n) {
        ll p; cin >> p;
        adj[p - 1].push_back(i);
    }

    ll marked = 0;
    function<ll(ll, ll)> dfs = [&](ll u, ll s) -> ll {
        s += m[u];
        if (s > l) return 0;
        marked++;
        if (all_of(all(adj[u]), [&](ll v) { return s + m[v] > l; }))
            return 1;
        return max(1ll, accumulate(all(adj[u]), 0LL, [&](ll a, ll v) {
            return a + dfs(v, s);
        }) - 1);
    };
    cout << dfs(0, 0) << ' ' << n - marked;
}
