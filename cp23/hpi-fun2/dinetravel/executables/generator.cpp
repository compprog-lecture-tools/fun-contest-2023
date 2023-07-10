#include <bits/stdc++.h>
#include <testlib.h>

using namespace std;

#define ll long long
#define rep(n, i) for (ll i = 0; i < n; i++)

const string_view SAMPLE1 = R"(4
0 1 2 3
0 1
3 2
)";
const string_view SAMPLE2 = R"(4
0 1 2 3
0 1
2 3
)";

template <class F>
void testcase(string name, string desc, F f) {
  ofstream desc_file(name + ".desc");
  desc_file << desc;
  string in_file = name + ".in";
  freopen(in_file.c_str(), "w", stdout);
  f();
}

void predefined(string name, string desc, string_view content) {
  testcase(name, desc, [&]() { cout << content; });
}

void sample(int num, string_view content) {
  auto num_str = toString(num);
  predefined("sample" + num_str, "Sample #" + num_str, content);
}

#define MAX 10000000
#define MIDI 10000

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  rnd.setSeed(553905892603446589ll);

  sample(1, SAMPLE1);
  sample(2, SAMPLE2);

  testcase("big-impossible", "big ask historians again", [] {
    ll n = MAX;

    vector<ll> timeline;
    rep(n, i) timeline.push_back(i);
    shuffle(timeline.begin(), timeline.end());

    vector<pair<ll, ll>> edges;
    rep(n - 1, i) { edges.push_back({i, i + 1 + rnd.next(n - 1 - i)}); }
    shuffle(edges.begin(), edges.end());
    edges.pop_back();
    
    swap(edges[rnd.next(n - 2)].first, edges[rnd.next(n - 2)].second);

    cout << n << "\n";
    rep(n, i) cout << timeline[i] << " \n"[i == n - 1];
    for (auto edge : edges) {
      cout << timeline[edge.first] << " " << timeline[edge.second] << "\n";
    }
  });

  testcase("big-lasagna-separate", "big with unconnected lasagna", [] {
    ll n = MAX;

    vector<ll> timeline;
    rep(n, i) timeline.push_back(i);
    shuffle(timeline.begin(), timeline.end());

    vector<pair<ll, ll>> edges;
    rep(n - 2, i) { edges.push_back({i, i + 1 + rnd.next(n - 2 - i)}); }
    shuffle(edges.begin(), edges.end());

    cout << n << "\n";
    rep(n, i) cout << timeline[i] << " \n"[i == n - 1];
    for (auto edge : edges) {
      cout << timeline[edge.first] << " " << timeline[edge.second] << "\n";
    }
  });

  testcase("big", "big", [] {
    ll n = MAX;

    vector<ll> timeline;
    rep(n, i) timeline.push_back(i);
    shuffle(timeline.begin(), timeline.end());

    vector<pair<ll, ll>> edges;
    rep(n - 1, i) { edges.push_back({i, i + 1 + rnd.next(n - 1 - i)}); }
    shuffle(edges.begin(), edges.end());
    edges.pop_back();

    cout << n << "\n";
    rep(n, i) cout << timeline[i] << " \n"[i == n - 1];
    for (auto edge : edges) {
      cout << timeline[edge.first] << " " << timeline[edge.second] << "\n";
    }
  });

  return 0;
}