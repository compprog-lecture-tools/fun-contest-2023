#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<pair<int,int>>>& g, vector<int>& dist, vector<int>& parent, vector<bool>& visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
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

    int c; int n;
    cin >> c >> n;

    int u, v, w;
    vector<vector<pair<int,int>>> g(n);

    for (int i = 0; i < n-1; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    //find longest path in tree

    vector<int> dist(n, 0);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    bfs(g, dist, parent, visited, 0);

    int max_dist = 0;
    int max_node = 0;
    for (int i = 0; i < n; i++) {
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
    for (int i = 0; i < n; i++) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
        }
    }

    if(max_dist > c) cout << "NO: " << max_dist << endl;
    else cout << "YES: " << max_dist << endl;

    return 0;
}