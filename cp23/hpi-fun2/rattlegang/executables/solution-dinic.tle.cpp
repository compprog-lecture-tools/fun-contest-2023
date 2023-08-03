#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using ll = long long;

struct edge {
    ll from, to, flow, cap;
    edge* rev = nullptr;
};

using Graph = vector<vector<edge*>>;
ll INF = LLONG_MAX;

void add_edge(ll a, ll b, ll cap, Graph& g) {
    auto ab = new edge{a, b, 0, cap};
    auto ba = new edge{b, a, 0, cap}; // undirected
    // auto ba = new edge{b, a, 0, 0}; // directed
    ab->rev = ba;
    ba->rev = ab;
    g[a].push_back(ab);
    g[b].push_back(ba);
};

ll dfs_dinic(ll v, ll aug, ll t, Graph& g, vector<ll>& next, vector<ll> &dist) {
    if(v == t) return aug;
    for(ll& i = next[v]; i < g[v].size(); i++) {
        auto e = g[v][i];
        if(e->flow == e->cap) continue;
        if(dist[e->to] != dist[v] + 1) continue;
        ll pushed = dfs_dinic(e->to, min(aug, e->cap - e->flow), t, g, next, dist);
        if(pushed == 0) continue;
        e->flow += pushed;
        e->rev->flow -= pushed;
        return pushed;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    //content

    ll n, m, s, t;
    // read graph size
    cin >> n;
    m = n * 3 / 2 + (2 * n);
    n += 2;
    s = 0;
    t = n - 1;

    Graph g(n);
    // add edges with add_edge
    rep(i, n / 2 - 1) {
        add_edge(s, i + 1, 1, g);
        add_edge(i + n / 2, t, 1, g);
    }
    rep(i, (n-2) * 3 / 2) {
        ll a, b;
        cin >> a >> b;
        add_edge(a, b, 1, g);
    }

    ll flow = 0;
    while(true) {
        vector<ll> dist(n, INF);
        dist[s] = 0;
        queue<ll> q({s});
        while(!q.empty()) {
            auto v = q.front(); q.pop();
            for(auto e : g[v]) {
                if(dist[e->to] == INF && e->flow < e->cap) {
                    q.push(e->to);
                    dist[e->to] = dist[v] + 1;
                }
            }
        }
        if(dist[t] == INF) break;
        vector<ll> next(n, 0);
        ll aug;
        while(aug = dfs_dinic(s, INF, t, g, next, dist)) flow += aug;
    }

    cout << flow << endl;

    return 0;
}