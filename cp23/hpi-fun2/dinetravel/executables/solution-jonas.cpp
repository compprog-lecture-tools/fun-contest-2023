#include <bits/stdc++.h>

using namespace std;

#define rep(a, b) for (int a = 0; a < (b); a++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> time(n), rank(n), deg(n);
  rep(i, n) {
    cin >> time[i];
    rank[time[i]] = i;
  }

  rep(i,n-2) {
    int a,b; cin >> a >> b;
    deg[a]++;
    if (a == b || rank[a] > rank[b] || deg[a] > 1 || deg[time.back()] > 0)
      return cout << "ask historians again", 0;
  }

  rep(i,n) {
    if (deg[i] == 0 && i != time.back()) {
      cout << n - rank[i] - 1 << endl << i << ' ' << time.back() << endl;
      return 0;
    }
  }

  return 0;
}
