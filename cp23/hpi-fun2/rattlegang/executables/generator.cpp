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
1 6
1 7
1 8
2 6
2 8
2 9
3 6
3 9
3 10
4 7
4 8
4 10
5 7
5 9
5 10
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
    rnd.setSeed(-8828216307506013167ll);

    sample(1, SAMPLE1);
    sample(2, SAMPLE2);

    return 0;
}