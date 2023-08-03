#include <bits/stdc++.h>

#define rep(i, b) for (ll i = 0; i < (b); ++i)
#define all(a) a.begin(), a.end()
#define sz(x) static_cast<ll>((x).size())

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vvi adj(n);
    rep(i, m) {
        ll u, v; cin >> u >> v;
        adj[--u].push_back(--v), adj[v].push_back(u);
    }

    vi seen(n);
    ll ans = 0;
    rep(i, n) sort(all(adj[i]), [&](ll a, ll b) { return sz(adj[a]) > sz(adj[b]); });
    rep(s, n) {
        if (seen[s]) continue;
        vi q{s};
        seen[s] = true;
        rep(j, sz(q))
            for (ll v: adj[q[j]])
                if (!seen[v]++) q.push_back(v);
        rep(i, sz(q)) reverse(all(adj[q[i]]));
        rep(i, sz(q)-1) seen[q[i]] = 0;
        queue<ll> Q({q.back()});
        while (!Q.empty()) {
            ll u = Q.front(); Q.pop();
            for (ll v: adj[u])
                if (!seen[v]++) Q.push(v);
            ans = max(ans, sz(Q)+1);
        }
    }
    cout << ans << endl;
    return 0;
}
