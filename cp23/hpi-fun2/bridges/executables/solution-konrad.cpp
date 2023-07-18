#include "bits/stdc++.h"
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n);
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[--u].emplace_back(--v, i);
		adj[v].emplace_back(u, i);
	}
	vector<int> ans, depth(n, -1);
	function<int(int,int,int)> dfs = [&] (int u, int d, int e) {
		int up{0}; // Number of Edges to a node with lower depth
		depth[u] = d;
		for (auto [v, i] : adj[u]) {
			if (depth[v] == -1) // Tree Edge
				up += dfs(v, d + 1, i);
			up += (d > depth[v]) - (d < depth[v]);
		}
		if (up == 1)
			ans.push_back(e);
		return up;
	};
	dfs(0, 0, 0);
	sort(begin(ans), end(ans));
	cout << size(ans) << '\n';
	for (int i : ans)
		cout << i << ' ';
	return 0;
}

