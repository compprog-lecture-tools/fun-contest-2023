#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;


const string_view SAMPLE1 = R"(2
1 1 1
1 1 2
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
    rnd.setSeed(-1143501878491944586ll);

    sample(1, SAMPLE1);
    
    testcase("empty", "empty", []{
        println(0);
    });


    testcase("small-x", "two cubes differ by x", []{
        println(2);
        println(1, 1, 1);
        println(2, 1, 1);
    });

    testcase("small-y", "two cubes differ by y", []{
        println(2);
        println(1, 1, 1);
        println(1, 2, 1);
    });

    testcase("small-z", "two cubes differ by z", []{
        println(2);
        println(1, 1, 1);
        println(1, 1, 2);
    });


    const long long MAX_COORDINATE = 10e12;
    const int MAX_N = 10e4;

    for (int i = 0; i < 10; i++) {
		testcase("random"+to_string(i), "random", []{
			int n = rnd.next(MAX_N);
            println(n);
            for(int i = 0; i < n; i++) {
                long long x = rnd.next(MAX_COORDINATE);
                long long y = rnd.next(MAX_COORDINATE);
                long long z = rnd.next(MAX_COORDINATE);
                println(x, y, z);
            }
		});
	}

    return 0;
}