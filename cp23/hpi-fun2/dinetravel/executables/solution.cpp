#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(n, i) for (ll i = 0; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int id_by_time[n];
    int time_by_id[n];
    rep(n, time)
    {
        int id;
        cin >> id;
        id_by_time[time] = id;
        time_by_id[id] = time;
    }

    vector<int> graph[n]; // for each event, what caused it
    rep(n - 2, i)
    {
        int from, to;
        cin >> from >> to;
        if (time_by_id[to] < time_by_id[from])
        {
            cout << "ask historians again\n";
            return 0;
        }
        graph[to].push_back(from);
    }

    vector<bool> connected_to_lasagna(n, false);
    queue<ll> qrious; // about which events we are curious
    for (qrious.push(id_by_time[n - 1]); !qrious.empty(); qrious.pop())
    {
        auto event = qrious.front();
        connected_to_lasagna[event] = true;
        for (auto cause : graph[event])
            qrious.push(cause);
    }

    int last_not_connected_event;
    for (int i = n - 2; i >= 0; i--)
        if (!connected_to_lasagna[i])
        {
            last_not_connected_event = i;
            break;
        }

    int number_of_possibilities_for_connections = n - 1 - time_by_id[last_not_connected_event];
    cout << number_of_possibilities_for_connections << "\n";
    cout << last_not_connected_event << " " << id_by_time[n - 1];

    return 0;
}
