#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(n, i) for (ll i = 0; i < n; i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<ll> id_by_time(n);
  vector<ll> time_by_id(n);
  rep(n, time) {
    ll id;
    cin >> id;
    id_by_time[time] = id;
    time_by_id[id] = time;
  }

  vector<vector<ll>> graph(n);  // for each event, what caused it
  rep(n - 2, i) {
    ll from, to;
    cin >> from >> to;
    if (time_by_id[to] < time_by_id[from]) {
      cout << "ask historians again\n";
      return 0;
    }
    graph[to].push_back(from);
  }

  vector<bool> connected_to_lasagna(n, false);
  queue<ll> qrious;  // times of events about which we are curious
  for (qrious.push(n - 1); !qrious.empty(); qrious.pop()) {
    auto time_of_event = qrious.front();
    auto event = id_by_time[time_of_event];
    connected_to_lasagna[time_of_event] = true;
    for (auto cause : graph[event]) qrious.push(time_by_id[cause]);
  }

  // cout << "visited: ";
  // rep(n, i) cout << (connected_to_lasagna[i] ? 'x' : '_');
  // cout << endl;

  ll last_not_connected_time;
  for (ll i = n - 2; i >= 0; i--)
    if (!connected_to_lasagna[i]) {
      last_not_connected_time = i;
      break;
    }

  ll number_of_possibilities_for_connections = n - 1 - last_not_connected_time;
  cout << number_of_possibilities_for_connections << "\n";
  cout << id_by_time[last_not_connected_time] << " " << id_by_time[n - 1];

  return 0;
}
