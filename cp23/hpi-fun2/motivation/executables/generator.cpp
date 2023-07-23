#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;

const string_view SAMPLE1 = R"(
  11
  2 5 3 7 2 1 10 4 1 8 2
  1 2 2 2 5 5 1 8 8 8
)";

const string_view SAMPLE2 = R"(
  5 7
  1 5 10 -2 -2
  1 1 3 3
)";

const string_view SAMPLE3 = R"(´
  5 7
  8 5 10 -2 -2
  1 1 3 3
)";

void long_increasing_chain_case() {
  const auto employees = size_t{100'000};
  const auto motivational_level = size_t{5'000};

  cout << employees << motivational_level << endl;
  for (auto i = size_t{0}; i < employees; ++i) {
    cout << 1;
  }
  cout << endl;

  for (auto i = size_t{1}; i < employees; ++i) {
    cout << i << endl;
  }
}

int main(int argc, char* argv[]) {
  predefined("pred1", "Sample #1", SAMPLE1);
  predefined("pred2", "Sample #2", SAMPLE2);
  predefined("pred3", "Sample #3", SAMPLE3);

  
}