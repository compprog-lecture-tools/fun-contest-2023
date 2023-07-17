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

template <class T>
T edmondsKarp(vector<unordered_map<int, T>>& graph, int source, int sink) {
  assert(source != sink);
  T flow = 0;
  vi par(sz(graph)), q = par;
  for (;;) {
    fill(all(par), -1);
    par[source] = 0;
    int ptr = 1;
    q[0] = source;
    rep(i, 0, ptr) {
      int x = q[i];
      for (auto e : graph[x]) {
        if (par[e.first] == -1 && e.second > 0) {
          par[e.first] = x;
          q[ptr++] = e.first;
          if (e.first == sink) goto out;
        }
      }
    }
    return flow;
  out:
    T inc = numeric_limits<T>::max();
    for (int y = sink; y != source; y = par[y])
      inc = min(inc, graph[par[y]][y]);
    flow += inc;
    for (int y = sink; y != source; y = par[y]) {
      int p = par[y];
      if ((graph[p][y] -= inc) <= 0) graph[p].erase(y);
      graph[y][p] += inc;
    }
  }
}

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

  ll min_rate = LONG_LONG_MAX;

  rep(i, 0, m) {
    vector<unordered_map<int, ll>> g(n);
    rep(j, 0, m) {
      // Skip edge i
      if (j == i) continue;
      auto& l = links[j];

      g[l.a][l.b] = l.r;
      g[l.b][l.a] = l.r;
    }

    ll f = edmondsKarp(g, 0, n - 1);
    min_rate = min(min_rate, f);
  }

  cout << min_rate << endl;

  return 0;
}
