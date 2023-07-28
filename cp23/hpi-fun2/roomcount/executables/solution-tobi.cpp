#include <bits/extc++.h>

#define rep(i, b) for (ll i = 0; i < (b); ++i)
#define all(a) a.begin(), a.end()
#define sz(x) static_cast<ll>((x).size())

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vvi adj(n);
    rep(i, m) {
        ll u, v; cin >> u >> v;
        adj[--u].push_back(--v), adj[v].push_back(u);
    }

    vi seen(n), deg(n);
    ll ans = 0;
    rep(i, n) sort(all(adj[i]), [&](ll a, ll b) { return sz(adj[a]) > sz(adj[b]); });
    rep(i, n) deg[i] = sz(adj[i]);
    rep(s, n) {
        if (seen[s]) continue;
        seen[s] = true;
        vi q{s};
        rep(j, sz(q))
            for (ll v: adj[q[j]])
                if (!seen[v]++) q.push_back(v);
        rep(i, sz(q)) reverse(all(adj[q[i]]));
        __gnu_pbds::priority_queue<pii, greater<>> pq;
        vector<decltype(pq)::point_iterator> nodes(n);
        pq.push({deg[q.back()], q.back()});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (!deg[u]) continue;
            deg[u] = 0;
            for (ll v: adj[u]) {
                if (!deg[v]) continue;
                if (nodes[v] == nullptr) nodes[v] = pq.push({--deg[v], v});
                else pq.modify(nodes[v], {--deg[v], v});
            }
            ans = max(ans, sz(pq)+1);
        }
    }
    cout << ans << endl;
    return 0;
}