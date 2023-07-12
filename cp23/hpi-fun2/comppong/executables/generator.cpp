#include <bits/stdc++.h>
#include <testlib.h>

using namespace std;

const string_view SAMPLE1 = R"(1
5 4
2  3  1  4 -2
-2  2 -4 -1  2
-3 -5 -1  6 -5
-1 -2  2  6  9
)";

template <class F> void testcase(string name, string desc, F f) {
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

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  rnd.setSeed(5120471233170915017ll);

  sample(1, SAMPLE1);

  testcase("random", "random", []() {
    int n = 1000;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << rnd.next(-10, 10) << ' ';
      }
      cout << endl;
    }
  });

  return 0;
}
