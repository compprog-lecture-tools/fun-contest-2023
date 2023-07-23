#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;

const string_view SAMPLE1 = R"(
  11
  2 5 3 7 2 1 10 4 1 8 2
  1 2 2 2 5 5 1 8 8 8
)";

const string_view SAMPLE2 = R"()";

const string_view SAMPLE3 = R"()";

int main(int argc, char* argv[]) {
  predefined("pred1", "Sample #1", SAMPLE1);
  predefined("pred2", "Sample #2", SAMPLE2);
  predefined("pred3", "Sample #3", SAMPLE3);
}