
#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define endl        '\n'
#define read(type, name)    type name; cin >> name

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed;

  read(int, n);
  read(int, m);

  vector<vector<int>> graph(n);
  vector<bool> found(n, false);
  rep(i, m) {
    read(int, a);
    read(int, b);
    a--; b--;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  size_t maxOverlap = 0;

  rep(initialNode, n) {
    if (found[initialNode]) continue;
    found[initialNode] = true;
    bool foundAnyNodes = false;
    int minDegreeNode = initialNode;

    queue<int> bfsQ;
    bfsQ.push(initialNode);
    while (!bfsQ.empty()) {
      int currentNode = bfsQ.front();
      bfsQ.pop();

      for (int overlappingNode : graph[currentNode]) {
        if (found[overlappingNode]) continue;
        found[overlappingNode] = true;
        bfsQ.push(overlappingNode);
        foundAnyNodes = true;
        if (graph[overlappingNode] < graph[minDegreeNode]) minDegreeNode = overlappingNode;
      }
    }

    // Handle connected component with a singe node
    if (!foundAnyNodes) {
      maxOverlap = max(maxOverlap, (size_t)1);
      continue;
    }

    int startNode = minDegreeNode;

    vector<bool> used(n, false);
    int pastIntervals = 0;
    // pairs: first is number of intervals that started before this interval ended, second is interval/node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> currentOverlap;

    currentOverlap.push({graph[startNode].size(), startNode});
    used[startNode] = true;

    for (int overlappingNode : graph[startNode]) {
      currentOverlap.push({graph[overlappingNode].size(), overlappingNode});
      used[overlappingNode] = true;
    }

    while (!currentOverlap.empty()) {
      maxOverlap = max(maxOverlap, currentOverlap.size());

      int minScore = currentOverlap.top().first;
      while (currentOverlap.top().first == minScore) {
        currentOverlap.pop();
        pastIntervals++;
        if (currentOverlap.empty()) break;
      }
      if (currentOverlap.empty()) break;

      for (int overlappingNode : graph[currentOverlap.top().second]) {
        if (used[overlappingNode]) continue;
        currentOverlap.push({pastIntervals + graph[overlappingNode].size(), overlappingNode});
        used[overlappingNode] = true;
      }
    }
  }

  cout << maxOverlap << endl;

  return 0;
}
