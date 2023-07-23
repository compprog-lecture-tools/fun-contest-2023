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

int maxLengthTestcase(int maxSize) {
  int n = maxSize;
  int m = n - 1;

  cout << n << " " << m << endl;

  for (int i = 1; i <= m; i++) {
    cout << i << " " << i + 1 << endl;
  }
  return m;
}

int maxWidthTestcase(int maxSize) {
  int n = sqrt(2 * maxSize);
  int m = n * (n-1) / 2;

  cout << n << " " << m << endl;

  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cout << i << " " << j << endl;
    }
  }
  return m;
}

int minTestcase() {
  cout << "2 1" << endl;
  cout << "1 2" << endl;
  return 1;
}

int minTwoComponentsTestcase() {
  cout << "3 1" << endl;
  cout << "2 3" << endl;
  return 1;
}

void intervalGraph(vector<int> &intervalStarts, int intervalLength, vector<pair<int, int>> &edges, int offset) {
  sort(intervalStarts.begin(), intervalStarts.end());
  for (int i = 0; i < intervalStarts.size(); i++) {
    int end = intervalStarts[i] + intervalLength;
    int iterator = i + 1;
    while (iterator < intervalStarts.size() && intervalStarts[iterator] < end) {
      edges.push_back({offset + i, offset + iterator++});
    }
  }
}

int randomTestcase(int intervalLength, int nodesPerComponent, int maxStart, int components = 1) {
  int n = nodesPerComponent * components;
  vector<pair<int, int>> edges;
  for (int i = 0; i < components; i++) {
    vector<int> intervalStarts;
    for (int j = 0; j < nodesPerComponent; j++) {
      intervalStarts.push_back(rnd.next(0, maxStart));
    }
    intervalGraph(intervalStarts, intervalLength, edges, i * nodesPerComponent);
  }
  shuffle(edges.begin(), edges.end());

  vector<int> randomPermutation(n);
  iota(randomPermutation.begin(), randomPermutation.end(), 0);
  shuffle(randomPermutation.begin(), randomPermutation.end());

  cout << n << " " << edges.size() << endl;
  for (auto& edge : edges) {
    cout << (randomPermutation[edge.first] + 1) << " " << (randomPermutation[edge.second] + 1) << endl;
  }
  return edges.size();
}

template <class F>
void testcase(string name, string desc, F f) {
    ofstream desc_file(name + ".desc");
    desc_file << desc;
    string in_file = name + ".in";
    freopen(in_file.c_str(), "w", stdout);
    int m = f();
    desc_file << ", m = " << m;
}

void predefined(string name, string desc, string_view content) {
    ofstream desc_file(name + ".desc");
    desc_file << desc;
    string in_file = name + ".in";
    freopen(in_file.c_str(), "w", stdout);
    cout << content;
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
      int intervalLength = rnd.next(5, 150);
      testcase("random_testcase_" + to_string(i),
               "random testcase with interval length = " + to_string(intervalLength) + ", n = " + to_string(n),
               [&n, &intervalLength]() -> int { return randomTestcase(intervalLength, n, n * n / 100); });
    }

    for (int i = 0; i < 5; i++) {
      int n = rnd.next(20, 100);
      int intervalLength = rnd.next(5, 30);
      int components = rnd.next(2, 20);
      testcase("random_multi_component_testcase_" + to_string(i),
               "random testcase with at least " + to_string(components) + " components, interval length = "
               + to_string(intervalLength) + ", n = " + to_string(n * components),
               [&n, &intervalLength, &components]() -> int {
        return randomTestcase(intervalLength, n, n * n / 100, components); });
    }

    int maxSize = 100000;
    testcase("max_size_length",
             "max length testcase with n = " + to_string(maxSize),
             [&maxSize]() -> int { return maxLengthTestcase(maxSize); });

    testcase("max_size_width",
             "max width testcase with n = " + to_string(maxSize),
             [&maxSize]() -> int { return maxWidthTestcase(maxSize); });

    testcase("max_size_random",
             "max size random testcase with n = " + to_string(maxSize / 10),
             [&maxSize]() -> int { return randomTestcase(100, maxSize / 10, maxSize); });

    testcase("min_size", "min testcase with n = 2", []() -> int { return minTestcase(); });

    testcase("min_two_components", "min testcase with n = 3", []() -> int { return minTwoComponentsTestcase(); });

    return 0;
}
