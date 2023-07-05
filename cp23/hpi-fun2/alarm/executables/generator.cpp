#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;


const string_view SAMPLE1 = R"(3
50 10 2.5
40 5 2.5
50 0 2.5 
)";

const string_view SAMPLE2 = R"(1 
50 5 4.999
)";

const string_view SAMPLE3 = R"(1
50 5 5
)";

const string_view SAMPLE4 = R"(3
50 10 2.5
50 5 2.5
50 0 2.5 
)";


const string_view HSAMPLE1 = R"(3
50 8 2.5
25 1 3
80 3 6 
)";

const string_view HSAMPLE2 = R"(1 
50 5 4.999999999)";


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
    rnd.setSeed(7368683479736286663ll);

    const int MAX = 1e6;

    sample(1, SAMPLE1);
    sample(2, SAMPLE2);
    sample(3, SAMPLE3);
    sample(4, SAMPLE4);

    testcase("possible small S shape", "possible with a S shaped path", HSAMPLE1);

    testcase("possible small with double", "fails if floats are used for the radius", HSAMPLE2);

    testcase("many random points", "random ranges", []{
        cout << Max << endl;
        rep(i, MAX){
            int x = rnd.next(0.0, 100.0);
            int y = rnd.next(0.0, 10.0);
            int r = rnd.next(0.0, 0.005);
            cout << x << " " << y << " " << r << endl;
        }
    });

    testcase("many random points with relative high radius", "random ranges", []{
        cout << Max << endl;
        rep(i, MAX){
            int x = rnd.next(0.0, 100.0);
            int y = rnd.next(0.0, 10.0);
            int r = rnd.next(5.0, 10.0);
            cout << x << " " << y << " " << r << endl;
        }
    });

    testcase("many random points with a corridor on top", "random ranges", []{
        cout << Max << endl;
        rep(i, MAX){
            int x = rnd.next(0.0, 100.0);
            int y = rnd.next(0.0, 9.5);
            int r = rnd.next(0.0, 0.05);
            cout << x << " " << y << " " << r << endl;

        }
    });

    

    return 0;
}