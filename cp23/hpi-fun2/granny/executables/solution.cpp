#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <climits>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<pair<ll,int> > >;

void dijkstra(Graph &g, vector<ll> &dist, int s){
    vector<bool> marked(g.size(),false);

    priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int>>> backlog;
    backlog.emplace(0,s);
    dist[s] = 0;

    while (!backlog.empty()){
        auto [length,idx] = backlog.top();
        backlog.pop();

        if (marked[idx]) continue;
        marked[idx] = true;

        for (auto &[l,i]: g[idx]) {
            if(marked[i]) continue;
            if(dist[i] > dist[idx] + l){
                dist[i] = dist[idx] + l;
                backlog.emplace(dist[i],i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n,m;
    cin >> n >> m;

    Graph g(n);
    Graph inG(n);

    while (m--){
        int a, b, t;
        cin >> a >> b >> t;
        a--;b--;

        g[a].emplace_back(t,b);
        inG[b].emplace_back(t, a);
    }

    vector<ll> distStart(n, LLONG_MAX/10);
    vector<ll> distEnd(n, LLONG_MAX/10);

    dijkstra(g,distStart, 0);
    dijkstra(inG,distEnd, n-1);
    ll shortestTime = distStart[n-1];

    for (int i = 0; i < n-1; ++i) {
        if(i)
            shortestTime = min(shortestTime, distStart[i] + distEnd[i-1]);
        shortestTime = min(shortestTime, distStart[i] + distEnd[i+1]);
    }

    cout << shortestTime << endl;

    return 0;
}