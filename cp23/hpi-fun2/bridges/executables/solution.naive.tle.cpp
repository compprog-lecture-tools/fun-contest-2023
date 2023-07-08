#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using ll = long long;
using namespace std;
typedef pair<ll, ll> pll;

bool bfs(vector<vector<pll>>& graph, ll u, ll v, ll s) {
    ll n = graph.size();
    vector<bool> visited(n, false);
    queue<ll> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        ll curr = q.front();
        q.pop();

        for (pll edge : graph[curr]) {
            ll node = edge.first;
            if ((curr == u && node == v) || (curr == v && node == u))
                continue;  // Skip the edge (u, v)
            if (!visited[node]) {
                visited[node] = true;
                q.push(node);
            }
        }
    }

    // Check if all edges are reachable
    for (ll i = 0; i < n; i++) {
        if (!visited[i])
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m; cin >> n >> m;
    vector<vector<pll>> graph(n, vector<pll>());
    for(ll i=1; i<=m; i++){
        ll u, v; cin >> u >> v;
        u--; v--;
        graph[u].emplace_back(v, i);
        graph[v].emplace_back(u, i);
    }


    vector<ll> result;
    for(ll i = 0 ; i < n ; i++){
        for(auto edge : graph[i]) {
            if(std::find(result.begin(), result.end(), edge.second) != result.end()) continue;
            if(!bfs(graph, i, edge.first, 0)) result.emplace_back(edge.second);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for(auto r : result) cout << r << " ";

    return 0;
}