#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;


const string_view SAMPLE1 = R"(3 1
2 3 1)"; // 1

const string_view SAMPLE2 = R"(3 1
1 2 1)"; // 1

const string_view SAMPLE3 = R"(3 2
1 2 0
2 3 1)"; // 0

const string_view SAMPLE4 = R"(3 2
1 2 1
2 3 0)"; // 0

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

void bigCase(){
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<pair<ll,int> > >;

    ll n = pow(10,6);
    ll maxL = pow(10,5);

    std::srand(42);
    Graph g(n);
    ll m = 0;
    vector<int> backlog;
    vector<int> inTreeIndex;
    inTreeIndex.push_back(0);

    // backlog
    for(int i = 1; i < n; i++){
        backlog.push_back(i);
    }

    // build tree
    for(int i = 1; i < n; i++){
        m++;
        int r = rand()%inTreeIndex.size();
        ll t = rand()% maxL;
        g[r].emplace_back(t,backlog[i]);
        inTreeIndex.push_back(backlog[i]);
    }

    for (int i = 0; i < 5000; ++i) {
        int a = rand()%inTreeIndex.size();
        int b = rand()%inTreeIndex.size();

        if(a == b) continue;
        bool found = false;
        for (auto &e: g[a]) {
            if(e.second == b) {
                found = true;
                break;
            }
        }
        if(!found) {
            ll t = rand()% maxL;
            g[a].emplace_back(t,b);
            m++;
        }
    }

    cout << n << " " << m << endl;
    for (int a = 0; a < n; ++a) {
        for (auto &b: g[a]) {
            cout << a << " " << b.second << " " << b.first << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(-2611193603731665810ll);

    // small examples
    
    sample(1, SAMPLE1);
    sample(2, SAMPLE2);
    sample(3, SAMPLE3);
    sample(4, SAMPLE4);

    // big sample
    testcase("bigTestcase","Its a big testcase",bigCase);
    
    return 0;
}