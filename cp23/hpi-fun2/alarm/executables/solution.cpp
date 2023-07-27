#include <bits/stdc++.h>
#include <vector>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using ll = long long;  


using namespace std;
using Graph = vector<vector<ll>>;

/*
-----------YES:
1 
50 5 4.999

3
50 10 2.5
40 5 2.5
50 0 2.5 


-----------NO:
1
50 5 5

3
50 10 2.5
50 5 2.5
50 0 2.5 





*/


void dfs(int v, int n, const Graph& g, vector<bool>& visited) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u])
            dfs(u, n, g, visited);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll width = 10;
    ll length = 100;

    ll n; 
    cin >> n;
    Graph g(n+2);
    // g[n] is n_upper and g[n+1] is n_lower
    vector<double> x_coord(n);
    vector<double> y_coord(n);
    vector<double> radius(n);

    rep(i, n){
        double x, y, r;
        cin >> x;
        cin >> y;
        cin >> r;
        x_coord[i] = x;
        y_coord[i] = y;
        radius[i] = r;
    }
    
    rep(i,n){
        if (y_coord[i] + radius[i] >= 10){
            g[n].push_back(i);
            g[i].push_back(n);
        }
        if (y_coord[i] - radius[i] <= 0){
            g[n+1].push_back(i);
            g[i].push_back(n+1);
        }
        rep(j,n){
            double dist = sqrt((x_coord[i] - x_coord[j])*(x_coord[i] - x_coord[j]) + (y_coord[i] - y_coord[j])*(y_coord[i] - y_coord[j]));
            if (dist <=  radius[i] + radius[j])
                g[i].push_back(j);      
        }
    }

    vector<bool> visited(n+2);
    dfs(n, n, g, visited);

    if(visited[n+1] == true)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    

    return 0;
}