#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void bfs(vector<vector<pair<ll,ll>>>& g, vector<ll>& dist, vector<ll>& parent, vector<bool>& visited, ll start) {
    queue<ll> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        ll curr = q.front();
        q.pop();

        for (auto& [next, weight] : g[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                dist[next] = dist[curr] + weight;
                parent[next] = curr;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll c; ll n;
    cin >> c >> n;

    ll u, v, w;
    vector<vector<pair<ll,ll>>> g(n);

    for (ll i = 0; i < n-1; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    //find longest path in tree

    vector<ll> dist(n, 0);
    vector<ll> parent(n, -1);
    vector<bool> visited(n, false);

    bfs(g, dist, parent, visited, 0);

    ll max_dist = 0;
    ll max_node = 0;
    for (ll i = 0; i < n; i++) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
            max_node = i;
        }
    }

    fill(dist.begin(), dist.end(), 0);
    fill(parent.begin(), parent.end(), -1);
    fill(visited.begin(), visited.end(), false);

    bfs(g, dist, parent, visited, max_node);

    max_dist = 0;
    for (ll i = 0; i < n; i++) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
        }
    }

    if(max_dist > c) cout << "NO: " << max_dist << endl;
    else cout << "YES: " << max_dist << endl;

    return 0;
}