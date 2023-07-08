#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using ll = long long;
using namespace std;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m; cin >> n >> m;
    vector<vector<pll>> graph(n, vector<pll>());
    for(ll i=0; i<m; i++){
        ll u, v; cin >> u >> v;
        graph[u].emplace_back(v, i);
    }
    cout << n << endl;
    for(ll i=1; i<=n; i++){
        cout << i << " ";
    }

    return 0;
}