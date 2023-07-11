#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(a, b) for (ll a = 0; a < (b); a++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> time(n), rank(n);
  vector<vector<int>> adj(n);
  rep(i, n) {
    cin >> time[i];
    rank[time[i]] = i;
  }

  rep(i,n-2) {
    int a,b; cin >> a >> b;
    adj[a].push_back(b);
    if (a == b || rank[a] > rank[b] || adj[a].size() > 1 || adj[time.back()].size() > 0)
      return cout << "ask historians again", 0;
  }

  rep(i,n) {
    if (adj[i].size() == 0 && i != time.back()) {
      cout << n - rank[i] - 1 << endl << i << ' ' << time.back() << endl;
      return 0;
    }
  }

  return 0;
}
