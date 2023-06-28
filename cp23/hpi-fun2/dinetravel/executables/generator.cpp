#include <testlib.h>
#include <bits/stdc++.h>

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
void testcase(string name, string desc, F f)
{
    ofstream desc_file(name + ".desc");
    desc_file << desc;
    string in_file = name + ".in";
    freopen(in_file.c_str(), "w", stdout);
    f();
}

void predefined(string name, string desc, string_view content)
{
    testcase(name, desc, [&]()
             { cout << content; });
}

void sample(int num, string_view content)
{
    auto num_str = toString(num);
    predefined("sample" + num_str, "Sample #" + num_str, content);
}

#define MAX 1000000

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    rnd.setSeed(553905892603446589ll);

    sample(1, SAMPLE1);
    sample(2, SAMPLE2);

    // testcase("big ask historians again", "big ask historians again", []
    //          {
    // 		int prefix = rnd.next(1, 9);
    // 		prefix = prefix*(MAX/10) + prefix*(MAX/100);
    // 		int l = rnd.next(MAX/100);
    // 		int r = rnd.next(l, MAX/100);
    // 		assert(r<=MAX/100);
    // 		assert(l<=r);
    // 		println(l+prefix, r+prefix); });

    // testcase("big with many possibilities", "big with many possibilities ", []
    //          {
    // 		int prefix = rnd.next(1, 9);
    // 		prefix = prefix*(MAX/10) + prefix*(MAX/100);
    // 		int l = rnd.next(MAX/100);
    // 		int r = rnd.next(l, MAX/100);
    // 		assert(r<=MAX/100);
    // 		assert(l<=r);
    // 		println(l+prefix, r+prefix); });

    // testcase("big with few possibilities", "big with few possibilities ", []
    //          {
    // 		int prefix = rnd.next(1, 9);
    // 		prefix = prefix*(MAX/10) + prefix*(MAX/100);
    // 		int l = rnd.next(MAX/100);
    // 		int r = rnd.next(l, MAX/100);
    // 		assert(r<=MAX/100);
    // 		assert(l<=r);
    // 		println(l+prefix, r+prefix); });

    testcase("big with unconnected lasagna", "big with unconnected lasagna ", []
             {
                int n = MAX;

                ll timeline[n];
                rep(n, i) timeline[i] = i;
                // Fisher-Yates-shuffle, https://stackoverflow.com/questions/22850316/how-to-shuffle-elements-in-a-vector-randomly
                rep(n, k)
                {
                    ll r = k + rnd.next(MAX) % (n - k);
                    swap(timeline[k], timeline[r]);
                }

                ll causes[n];
                rep(n - 2, i) {
                    causes[i] = i + rnd.next(n - 2 - i);
                }

                vector<pair<ll, ll>> edges;
                rep(n - 2, i) {
                    edges.push_back({i, causes[i]});
                }
                rep(n, k)
                {
                    ll r = k + rnd.next(MAX) % (n - k);
                    swap(edges[k], edges[r]);
                }

                cout << n << "\n";
                rep(n, i)
                    cout << timeline[i] << " \n"[i == n - 1];
                for (auto edge : edges) {
                    cout << edge.first << " " << edge.second << "\n";
                } });

    return 0;
}