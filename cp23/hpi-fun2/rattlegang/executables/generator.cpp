#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;


const string_view SAMPLE1 = R"(6
1 4
1 5
1 6
2 4
2 5
2 6
3 4
3 5
3 6
)";

const string_view SAMPLE2 = R"(10
3 9
1 8
2 6
5 10
5 9
2 8
4 8
2 9
3 6
1 7
3 10
4 7
4 10
5 7
1 6
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

void testcase_for_size(int size) {
    int n = size;
    n -= n % 2; // make n even
    cout << n << endl;
    vector<int> a(n/2), b(n/2);
    iota(a.begin(), a.end(), 1);
    iota(b.begin(), b.end(), n/2+1);
    set<pair<int,int>> edges;
    for(int j = 0; j < 3; j++) {
        bool valid = false;
        while(!valid) {
            valid = true;
            shuffle(a.begin(), a.end());
            shuffle(b.begin(), b.end());
            // try again if this would reuse already existing edge
            for(int k = 0; k < n/2; k++)
                if (edges.find(make_pair(a[k], b[k])) != edges.end()) { valid = false; break; }
            if (!valid) continue;

            for(int k = 0; k < n/2; k++) {
                edges.emplace(a[k], b[k]);
                cout << a[k] << " " << b[k];
                if(j < 2 || k < n/2-1) cout << endl;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(-8828216307506013167ll);

    sample(1, SAMPLE1);
    sample(2, SAMPLE2);

    const int MAX_RANDOM_SIZE = 1e2;
    const int MAX_SIZE = 1e6;

    for(int i = 0; i < 20; i++) {
        testcase("small_random_size_" + to_string(i), "small_random_size", [](){
            testcase_for_size(rnd.next(6, MAX_RANDOM_SIZE));
        });
    }

    testcase("max_size", "max_size", [](){
        testcase_for_size(MAX_SIZE);
    });

    return 0;
}