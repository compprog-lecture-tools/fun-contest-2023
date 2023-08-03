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
    //auto ba = new edge{b, a, 0, cap}; // undirected
    auto ba = new edge{b, a, 0, 0}; // directed
    ab->rev = ba;
    ba->rev = ab;
    g[a].push_back(ab);
    g[b].push_back(ba);
};

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
        vector<edge*> inc(n, nullptr);
        queue<ll> q({s});
        while(!q.empty()) {
            auto v = q.front(); q.pop();
            for(auto e : g[v]) {
                if(!inc[e->to] && e->flow < e->cap) {
                    q.push(e->to);
                    inc[e->to] = e;
                }
            }
        }
        if(!inc[t]) break;
        ll aug = INF;
        for(ll v = t; v != s; v = inc[v]->from)
            aug = min(aug, inc[v]->cap - inc[v]->flow);
        flow += aug;
        for(int v = t; v != s; v = inc[v]->from) {
            inc[v]->flow += aug;
            inc[v]->rev->flow -= aug;
        }
    }

    cout << flow << endl;

    return 0;
}