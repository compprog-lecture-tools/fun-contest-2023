#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<pair<ll, ll> > >;

const string_view SAMPLE_ON_PDF = R"(6 8
1 2 5
1 3 7
1 4 3
2 6 4
3 2 5
3 4 2
4 5 1
5 6 2
)";

const string_view ANTI_DASH = R"(5 5
1 2 1
3 5 1
1 2 5
2 4 5
4 5 5)"; // 2

const string_view ANTI_UNDIRECTED = R"(3 3
1 2 5
2 3 5
1 3 1)";

const string_view SAMPLE1 = R"(3 1
2 3 1)"; // 1

const string_view SAMPLE2 = R"(3 1
1 2 1)"; // 1

const string_view SAMPLE3 = R"(3 2
1 2 0
2 3 1)"; // 0

template<class F>
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

void generateRandomTestcase(ll n, ll maxL, ll maxM) {
    vector<ll> backlog;
    set<pair<ll, ll>> edges;
    vector<tuple<ll, ll, ll>> outEdges;

    // backlog
    for (ll i = 1; i < n; i++) {
        backlog.push_back(i);
    }
    shuffle(backlog.begin(), backlog.end());

    // build tree
    for (ll i = 1; i < n; i++) {
        ll r = rnd.next(i);
        ll t = rnd.next(maxL);
        edges.emplace(r, backlog[i]);
        outEdges.emplace_back(t, r, i);
    }

    ll count = n - 1;
    while (outEdges.size() < maxM) {
        ll a = rnd.next(count);
        ll b = rnd.next(count);

        if (a == b) continue;
        if (edges.contains(pair(a, b))) continue;
        ll t = rnd.next(maxL);
        outEdges.emplace_back(t, a, b);
    }

    shuffle(outEdges.begin(), outEdges.end());
    cout << n << " " << outEdges.size() << endl;
    for (auto [time, src, dst]: outEdges) {
        cout << (src + 1) << " " << (dst + 1) << " " << time << endl;
    }
}

void bigTestcase() {
    generateRandomTestcase(1e5, 1e5, 1e5);
}

void smallTestcase1() {
    generateRandomTestcase(10, 50, 20);
}

void smallTestcase2() {
    generateRandomTestcase(10, 50, 50);
}

void smallTestcase3() {
    generateRandomTestcase(20, 1e5, 100);
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(-2611193603731665810ll);

    // small examples
    sample(1, SAMPLE_ON_PDF);
    predefined("smallTestcase1", "n = 3, m = 1; Dashing is necessary, dash from start", SAMPLE1);
    predefined("smallTestcase2", "n = 3, m = 1; Dashing is necessary, dash to end", SAMPLE2);
    predefined("smallTestcase3", "n = 3, m = 2; Dash even tho there is a connection", SAMPLE3);
    predefined("AntiAlwaysDash", "n = 5,m = 5; Dont dash!", ANTI_DASH);
    predefined("AntiUndirectedGraph", "n = 3, m = 3; The input graph should not be interpreted as undirected.",
               ANTI_UNDIRECTED);

    // big examples
    testcase("bigTestcase", "Random testcase, n = 1e6, max path length = 1e5, max edges = 1e6", generateRandomTestcase);
    vector<tuple<ll, ll, ll>> random_testcases = {
            tuple(10, 50, 20),
            tuple(10, 50, 50),
            tuple(20, 1e5, 100),
            tuple(25, 500, 100),
            tuple(25, 1e5, 150),
            tuple(50, 10, 500),
            tuple(50, 1e5, 700)
    };
    for (ll i = 0; i < 7; i++) {
        auto [n, max_t, max_m] = random_testcases[i];
        auto this_testcase = [&]() {
            generateRandomTestcase(n, max_t, max_m);
        };
        testcase("randomTestcase" + to_string(i),
                 "Random testcase " + to_string(i) + ", n = " + to_string(n) + ", max_t = " + to_string(max_t) + ", max_m = " + to_string(max_m), this_testcase);
    }
    return 0;
}