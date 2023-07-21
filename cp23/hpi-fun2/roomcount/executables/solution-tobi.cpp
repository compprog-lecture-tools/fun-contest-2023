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
    rep(S, n) {
        if (seen[S]) continue;
        vi q{S};
        seen[S] = 1;
        rep(j, sz(q))
            for (ll v: adj[q[j]])
                if (!seen[v]++) q.push_back(v);
        rep(i, sz(q)) reverse(all(adj[q[i]]));
        rep(i, sz(q)-1) seen[q[i]] = 0;
        vi evt(sz(q));
        q = {q.back()};
        ll open = 0;
        rep(i, sz(q)) {
            evt[i + sz(adj[q[i]]) - open++]++;
            ans = max(ans, open);
            open -= evt[i];
            for (ll v: adj[q[i]])
                if (!seen[v]++) q.push_back(v);
        }
    }
    cout << ans << endl;
    return 0;
}
