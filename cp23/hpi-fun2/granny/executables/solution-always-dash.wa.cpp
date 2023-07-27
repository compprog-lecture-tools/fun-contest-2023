#include <bits/stdc++.h>
#define rep(i, b) for (ll i = 0; i < (b); ++i)
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using vvp = vector<vector<pii>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vvp adj(2*n);
    rep(i, m) {
        ll u, v, w; cin >> u >> v >> w;
        --u; --v;
        adj[u].emplace_back(v, w);
        adj[u+n].emplace_back(v+n, w);
    }
    rep(i, n) {
        if (i > 0) adj[i].emplace_back(i-1+n, 0);
        if (i+1 < n) adj[i].emplace_back(i+1+n, 0);
    }

    vector<ll> dist(2*n, 1e17);
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    cout << dist[n-1+n] << endl;

    return 0;
}
