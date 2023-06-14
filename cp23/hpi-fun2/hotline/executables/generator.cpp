#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;


const string_view SAMPLE1 = R"(121 130
)";

const string_view SAMPLE2 = R"(992491 998041
)";

const string_view R_IS_ANSWER = R"(99000 102345
)";

const string_view BIG_GAP = R"(110000 1000000
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
    rnd.setSeed(-4938680848963769531ll);

	const int MAX = 1000000;

    sample(1, SAMPLE1);
    sample(2, SAMPLE2);
    predefined("pred1", "r is answer", R_IS_ANSWER);
    predefined("pred2", "big gap", BIG_GAP);

	for (int i = 0; i < 4; i++) {
		testcase("impossible"+to_string(i), "impossible", []{
			int prefix = rnd.next(1, 9);
			prefix = prefix*(MAX/10) + prefix*(MAX/100);
			int l = rnd.next(MAX/100);
			int r = rnd.next(l, MAX/100);
			assert(r<=MAX/100);
			assert(l<=r);
			println(l+prefix, r+prefix);
		});
	}

	for (int i = 0; i < 20; i++) {
		testcase("random"+to_string(i), "random ranges", []{
			int l = rnd.next(MAX);
			int r = rnd.next(l, MAX);
			assert(r<=MAX);
			assert(l<=r);
			println(l, r);
		});
	}

    return 0;
}
