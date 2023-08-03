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
  int a, b, r, i;
};

// Function to find the maximum flow in G(λ)
int findMaxFlow(const vector<Link>& links, int n, int lambda) {
  PushRelabel pr(n);
  for (const Link& link : links) {
    pr.addEdge(link.a, link.b, min(link.r, lambda));
    pr.addEdge(link.b, link.a, min(link.r, lambda));
  }
  return pr.calc(0, n - 1);
}

// Function to find the minimum cut S(λ) and q(λ)
ll findMinCut(const vector<Link>& links, int n, int lambda, vector<int>& S,
              int& q) {
  PushRelabel pr(n);
  for (const Link& link : links) {
    pr.addEdge(link.a, link.b, min(link.r, lambda));
    pr.addEdge(link.b, link.a, min(link.r, lambda));
  }
  ll val = pr.calc(0, n - 1);
  S.clear();
  q = 0;
  for (const Link& link : links) {
    if (pr.leftOfMinCut(link.a) && !pr.leftOfMinCut(link.b)) {
      S.push_back(link.i);
      q++;
    }
  }
  return val;
}

// Newton's method specialization for combinatorial optimization
int findOptimalLambda(const vector<Link>& links, int n, int max_flow_value) {
  int q, q_lambda;
  vector<int> S, S_lambda;
  int v = findMinCut(links, n, INT_MAX, S, q);

  float lambda = INT_MIN;  // Initialize lambda with a very large value
  // Find the initial lambda value
  for (auto& l : S) {
    lambda = max(lambda, float(links[l].r));
  }

  int v_lambda = findMinCut(links, n, lambda, S_lambda, q_lambda);

  // Iterate until v(lambda) >= max_flow_value
  while (v_lambda < max_flow_value && q_lambda != 0) {
    lambda = lambda + (max_flow_value - v_lambda) / float(q_lambda);
    v_lambda = findMinCut(links, n, lambda, S_lambda, q_lambda);
  }

  // weird edge case. it seems that lambda is our flow value then?
  if (q_lambda == 0) {
    cout << lambda << endl;
    exit(0);
  }

  return lambda;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a, b, r;

  cin >> n >> m;

  vector<Link> links;

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> r;
    a--;
    b--;
    links.push_back({a, b, r, i});
  }

  // Find the maximum flow in G
  int max_flow_value = findMaxFlow(links, n, numeric_limits<int>::max());

  // Find the optimal lambda value
  int optimal_lambda = findOptimalLambda(links, n, max_flow_value);

  cout << max_flow_value - optimal_lambda << endl;

  return 0;
}
