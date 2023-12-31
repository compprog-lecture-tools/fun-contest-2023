#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define sz(x) (int)(x).size()

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

struct PushRelabel {
  struct Edge {
    int dest, back;
    ll f, c;
  };
  vector<vector<Edge>> g;
  vector<ll> ec;
  vector<Edge*> cur;
  vector<vi> hs;
  vi H;
  PushRelabel(int n) : g(n), ec(n), cur(n), hs(2 * n), H(n) {}
  void addEdge(int s, int t, ll cap, ll rcap = 0) {
    if (s == t) return;
    g[s].push_back({t, sz(g[t]), 0, cap});
    g[t].push_back({s, sz(g[s]) - 1, 0, rcap});
  }
  void addFlow(Edge& e, ll f) {
    Edge& back = g[e.dest][e.back];
    if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
    e.f += f;
    e.c -= f;
    ec[e.dest] += f;
    back.f -= f;
    back.c += f;
    ec[back.dest] -= f;
  }
  ll calc(int s, int t) {
    int v = sz(g);
    H[s] = v;
    ec[t] = 1;
    vi co(2 * v);
    co[0] = v - 1;
    rep(i, 0, v) cur[i] = g[i].data();
    for (Edge& e : g[s]) addFlow(e, e.c);
    for (int hi = 0;;) {
      while (hs[hi].empty())
        if (!hi--) return -ec[s];
      int u = hs[hi].back();
      hs[hi].pop_back();
      while (ec[u] > 0)  // discharge u
        if (cur[u] == g[u].data() + sz(g[u])) {
          H[u] = 1e9;
          for (Edge& e : g[u])
            if (e.c && H[u] > H[e.dest] + 1) H[u] = H[e.dest] + 1, cur[u] = &e;
          if (++co[H[u]], !--co[hi] && hi < v)
            rep(i, 0, v) if (hi < H[i] && H[i] < v)-- co[H[i]], H[i] = v + 1;
          hi = H[u];
        } else if (cur[u]->c && H[u] == H[cur[u]->dest] + 1)
          addFlow(*cur[u], min(ec[u], cur[u]->c));
        else
          ++cur[u];
    }
  }
  bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

struct Link {
  int a, b, r;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a, b, r;

  cin >> n >> m;

  vector<Link> links;

  rep(i, 0, m) {
    cin >> a >> b >> r;
    a--;
    b--;
    links.push_back({a, b, r});
  }

  if (m == 0) {
    cout << 0 << endl;
    return 0;
  }

  ll min_rate = LLONG_MAX;

  rep(i, 0, m) {
    PushRelabel pr(n);
    rep(j, 0, m) {
      // Skip edge i
      if (j == i) continue;
      pr.addEdge(links[j].a, links[j].b, links[j].r);
      pr.addEdge(links[j].b, links[j].a, links[j].r);
    }

    ll f = pr.calc(0, n - 1);
    min_rate = min(min_rate, f);
  }

  cout << min_rate << endl;

  return 0;
}
