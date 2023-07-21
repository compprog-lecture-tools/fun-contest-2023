#include <bits/stdc++.h>

#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(a) a.begin(), a.end()
#define sz(x) static_cast<ll>((x).size())

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vvi adj(n);
    rep(i, 0, m) {
        ll u, v;
        cin >> u >> v;
        adj[--u].push_back(--v), adj[v].push_back(u);
    }

    vi seen1(n), seen2(n);
    ll ans = 0;
    rep(i, 0, n) sort(all(adj[i]), [&](ll a, ll b) { return sz(adj[a]) > sz(adj[b]); });
    rep(S, 0, n) {
        if (seen1[S]) continue;
        vi q{S};
        seen1[S] = 1;
        rep(j, 0, sz(q))
            for (ll v: adj[q[j]])
                if (!seen1[v]++) q.push_back(v);
        rep(i, 0, n) reverse(all(adj[i]));
        vi evt(sz(q));
        q = {q.back()};
        seen2[q[0]] = 1;
        ll open = 0;
        rep(i, 0, sz(q)) {
            evt[i + sz(adj[q[i]]) - open++]++;
            ans = max(ans, open);
            open -= evt[i];
            for (ll v: adj[q[i]])
                if (!seen2[v]++) q.push_back(v);
        }
    }
    cout << ans << endl;
    return 0;
}
