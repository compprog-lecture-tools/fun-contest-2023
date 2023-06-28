#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;

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

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    rnd.setSeed(553905892603446589ll);

    sample(1, SAMPLE1);
    sample(2, SAMPLE2);

    return 0;
}