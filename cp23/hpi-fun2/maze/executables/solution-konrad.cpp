#include <bits/stdc++.h>
using namespace std;

const string d{"NESW"};

void dfs(int x, vector<bool>& v, vector<int>& o) {
  v[x] = true;
  string s;
  cin >> s;
  if (s == "EXIT" || s == "-1")
    exit(0);
  for (int i = 0; i < 4; i++)
    if (s[i] == '_' && !v[x + o[i]])
      cout << d[i] << endl
           << (dfs(x + o[i], v, o), d[i ^ 2]) << endl,
          cin >> s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int w, h;
  cin >> w >> h;
  vector<bool> v(2 * w * h + 1);
  vector o{-w, 1, w, -1};
  dfs(w * h, v, o);
  return 0;
}
