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

const string_view MIN = R"(2 1
1 2
)";

const string_view MIN_2_COMPONENTS = R"(3 1
2 3
)";

const string_view ANTI_GREEDY_START = R"(9 14
8 2
8 3
3 4
4 2
2 3
4 8
4 1
1 5
5 7
6 5
6 9
9 7
6 7
9 5
)";

const string_view ANTI_GREEDY_MAX_DEGREE = R"(12 23
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5
3 8
6 7
6 8
6 9
7 8
7 9
8 9
6 10
6 11
6 12
10 11
10 12
11 12
)";

const string_view ANTI_GREEDY_ANY_FARTHEST_POINT = R"(8 18
1 2
2 3
2 4
2 5
3 4
3 5
3 6
3 7
3 8
4 5
4 6
4 8
5 6
5 7
5 8
5 7
6 8
7 8
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

int randomTestcase(int intervalLength, int nodesPerComponent, int maxStart, int components = 1, size_t maxSize = SIZE_MAX) {
  int n = nodesPerComponent * components;
  vector<pair<int, int>> edges;
  do {
    edges.clear();
    for (int i = 0; i < components; i++) {
      vector<int> intervalStarts;
      for (int j = 0; j < nodesPerComponent; j++) {
        intervalStarts.push_back(rnd.next(0, maxStart));
      }
      intervalGraph(intervalStarts, intervalLength, edges, i * nodesPerComponent);
    }
  } while (edges.size() > maxSize);
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

    predefined("min_size_testcase", "min testcase with n = 2, m = 1", MIN);
    predefined("min_two_components_testcase", "min testcase with 2 components, n = 3, m = 1", MIN_2_COMPONENTS);
    predefined("anti_greedy_start_testcase",
               "anti greedy testcase where the node with the lowest degree is in the middle of the graph",
               ANTI_GREEDY_START);
    predefined("anti_greedy_max_degree_testcase",
               "anti greedy testcase where the node with the highest degree is not in the largest clique",
               ANTI_GREEDY_MAX_DEGREE);
    predefined("anti_greedy_any_farthest_point_testcase",
               "anti greedy testcase that fails if just any farthest point is taken as the start node",
               ANTI_GREEDY_ANY_FARTHEST_POINT);

    for (int i = 0; i < 10; i++) {
      int n = rnd.next(100, 1000);
      int intervalLength = 5 + 15 * i;
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
    testcase("max_size_one_path",
             "max size testcase with one large path with n = " + to_string(maxSize),
             [&maxSize]() -> int { return maxLengthTestcase(maxSize); });

    testcase("max_size_one_clique",
             "max size testcase with one big clique with n = " + to_string(maxSize),
             [&maxSize]() -> int { return maxWidthTestcase(maxSize); });

    testcase("max_size_random",
             "max size random testcase with n = " + to_string(maxSize / 10),
             [&maxSize]() -> int { return randomTestcase(100, maxSize / 10, maxSize, 1, maxSize); });

    return 0;
}
