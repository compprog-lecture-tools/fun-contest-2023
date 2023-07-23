#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;


const string_view SAMPLE1 = R"(5 8
1 2
1 3
2 3
2 4
2 5
3 4
3 5
4 5
)";

const string_view SAMPLE2 = R"(5 4
3 1
2 5
4 2
4 5
)";

void maxLengthTestcase(int maxSize) {
  int n = maxSize;
  int m = n - 1;

  cout << n << " " << m << endl;

  for (int i = 1; i <= m; i++) {
    cout << i << " " << i + 1 << endl;
  }
}

void maxWidthTestcase(int maxSize) {
  int n = sqrt(2 * maxSize);
  int m = n * (n-1) / 2;

  cout << n << " " << m << endl;

  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cout << i << " " << j << endl;
    }
  }
}

void minTestcase() {
  cout << "2 1" << endl;
  cout << "1 2" << endl;
}

void minTwoComponentsTestcase() {
  cout << "3 << 1" << endl;
  cout << "2 3" << endl;
}

void intervalGraph(vector<int> &intervalStarts, int intervalLength, vector<pair<int, int>> &edges) {
  sort(intervalStarts.begin(), intervalStarts.end());
  for (int i = 0; i < intervalStarts.size(); i++) {
    int end = intervalStarts[i] + intervalLength;
    int iterator = i + 1;
    while (iterator < intervalStarts.size() && intervalStarts[iterator] < end) {
      edges.push_back({i + 1, ++iterator});
    }
  }
}

void randomTestcase(int intervalLength, int n, int maxStart) {
  vector<int> intervalStarts;
  for (int i = 0; i < n; i++) {
    intervalStarts.push_back(rnd.next(0, maxStart));
  }
  vector<pair<int, int>> edges;
  intervalGraph(intervalStarts, intervalLength, edges);
  shuffle(edges.begin(), edges.end());

  cout << n << " " << edges.size() << endl;
  for (auto& edge : edges) {
    cout << edge.first << " " << edge.second << endl;
  }
}

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
    rnd.setSeed(7889991971352209491ll);

    sample(1, SAMPLE1);
    sample(2, SAMPLE2);

    for (int i = 0; i < 10; i++) {
      int n = rnd.next(100, 1000);
      testcase("random_testcase_" + to_string(i), "random_testcase", [&n](){
        randomTestcase(100, n, n * n / 100);
      });
    }

    int maxSize = 1000000;
    testcase("max_size_length", "max_size_length", [&maxSize](){
      maxLengthTestcase(maxSize);
    });

    testcase("max_size_width", "max_size_width", [&maxSize](){
      maxWidthTestcase(maxSize);
    });

    testcase("min_size", "min testcase with 2 nodes, 1 edge", []() {
      minTestcase();
    });

    testcase("min_two_components", "min testcase with 3 nodes, 1 edge", []() {
      minTwoComponentsTestcase();
    });

    return 0;
}
