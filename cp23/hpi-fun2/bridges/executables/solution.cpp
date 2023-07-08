#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using ll = long long;
using namespace std;
typedef pair<ll, ll> pll;

void tarjan(ll u, ll parent ,ll& time, vector<bool>& visited, vector<ll>& tin, vector<ll>& low ,vector<ll>& result ,vector<vector<pll>>& graph){

    visited[u] = true;
    low[u] = tin[u] = time++;

    for(auto edge : graph[u]){
        ll v = edge.first;
        ll id = edge.second;

        if(v == parent) continue;

        if(!visited[v])
        {
            tarjan(v, u, time, visited, tin, low, result, graph);
            low[u] = min(low[u] ,low[v]);
            if(low[v] > tin[u]) result.push_back(id);
        }
        else low[u] = min(low[u] , tin[v]);
    }
}


/*void tarjanIterative(ll u, ll parent, ll& time, vector<bool>& visited, vector<ll>& tin, vector<ll>& low, vector<ll>& result, vector<vector<pll>>& graph) {
    stack<pair<ll, ll>> stk;
    stk.emplace(u, -1);

    while (!stk.empty()) {
        pair<ll, ll> cur = stk.top();
        ll v = cur.first;
        ll id = cur.second;
        stk.pop();

        if (!visited[v]) {
            visited[v] = true;
            low[v] = tin[v] = time++;
        }

        bool isBridge = true;
        for (auto edge : graph[v]) {
            ll nextV = edge.first;
            ll nextID = edge.second;

            if (nextV == parent) continue;

            if (!visited[nextV]) {
                stk.emplace(nextV, nextID);
                isBridge = false;
            } else {
                low[v] = min(low[v], tin[nextV]);  // Update low[v] using the already visited vertex's tin value
            }
        }

        if (id != -1 && isBridge && low[v] > tin[parent]) {
            result.push_back(id);
        }
    }
}*/


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

    ll time = 0;
    ll parent = -1;

    vector<bool>visited(n , false);
    vector<ll> tin(n ,-1);
    vector<ll> low(n , -1);
    vector<ll> result;

    for(ll i = 0 ; i < n ; i++){
        if(!visited[i])
            tarjan(i , parent ,time , visited , tin , low , result ,graph);
            //tarjanIterative(i, -1, time, visited, tin, low, result, graph);
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for(auto r : result) cout << r << " ";

    return 0;
}