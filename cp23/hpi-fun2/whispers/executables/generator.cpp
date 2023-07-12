#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;


const string_view SAMPLE1 = R"(3 4
0 1 1
1 2 1
2 3 2
2 4 1
)";

const string_view SAMPLE2 = R"(2 4
0 1 1
2 1 1
3 1 1
4 3 1
)";

const string_view NO_EDGE = R"(2 1
)";

const string_view STAR = R"(1 8
0 1 1
2 1 1
3 1 1
4 1 1
5 1 1
6 1 1
7 1 1
)";

const string_view WEIGHT_0 = R"(1 8
0 1 0
2 1 0
3 1 0
4 1 0
5 1 0
6 1 0
7 1 0
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

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(-2014268171001967338ll);

    sample(1, SAMPLE1);
    sample(2, SAMPLE2);
    sample(3, NO_EDGE);
    sample(4, STAR);
    sample(5, WEIGHT_0);

    const int max_n = 2e5;


    for (int i = 0; i < 20; i++) {
		testcase("random"+to_string(i), "random ranges", []{
			println(2, 3);
            println(0, 1, 1);
            println(1, 2, 1);
		});
    }


    testcase("random", "random ranges", []{
        int n = max_n;
        long long max_w = 100;
        long long c = 100000;
        cout << c << " " << n << endl;

        vector<int> nodes(n);
        iota(nodes.begin(), nodes.end(), 0);

        vector<int> parents(n-1, -1);
        vector<long long> weights(n-1, 0);

        for (int i = 0; i < n-1; i++) {
            int parent = rnd.next(i+1, n-1);
            parents[i] = parent;
            weights[i] = rnd.next(1, int(max_w));
        }

        for (int i = 0; i < n-1; i++) {
            cout << parents[i] << " " << i << " " << weights[i] << endl;
        }
    });


	testcase("big", "big weights", []{
        int n = max_n;
        long long max_w = 10000000000000;
        long long c = 1;
        cout << c << " " << n << endl;

        for(int i = 0; i < n-1; i++)
            cout << i << " " << i+1 << " " << max_w << endl;
    });

    return 0;
}
