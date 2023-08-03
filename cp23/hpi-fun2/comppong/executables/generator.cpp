#include <bits/stdc++.h>
#include <testlib.h>

using namespace std;

const string_view SAMPLE2 = R"(5 4
2 3 1 4 -2
-2 2 -4 -1 2
-3 -5 -1 6 -5
-1 -2 2 6 9
)";

const string_view SAMPLE1 = R"(3 3
-2 -1 -1
1 -1 1
1 2 -2
)";

const string_view SAMPLE3 = R"(1 8
-3
4
-1
-5
2
5
-1
2
)";

const string_view MULTIPLESOLUTIONS = R"(3 1
1 -1 1
)";

const string_view MULTIPLESOLUTIONS2 = R"(3 1
1 -3 1
)";

const string_view WHOLEFIELD = R"(4 4
1 1 1 1 
1 -1 -1 1
1 -1 -1 1
1 1 1 1
)";

const string_view SINGLECUP = R"(2 2
1 -1
-1 -1
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

void make_testcase_input(int w, int h)
{
  cout << w << " " << h << endl;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (i == 0 && j == 0)
        cout << 1;
      else if (i == h - 1 && j == w - 1)
        cout << -1;
      else
        cout << rnd.next(-100, 100);
      cout << " \n"[j == w - 1];
    }
  }
}

int main(int argc, char *argv[])
{
  registerGen(argc, argv, 1);
  rnd.setSeed(5120471233170915017ll);

  sample(1, SAMPLE1);
  sample(2, SAMPLE2);
  sample(3, SAMPLE3);
  predefined("multiple_solutions", "multiple_solutions", MULTIPLESOLUTIONS);
  predefined("multiple_solutions2", "multiple_solutions2", MULTIPLESOLUTIONS2);
  predefined("whole_field", "whole_field", WHOLEFIELD);
  predefined("single_cup", "single_cup", SINGLECUP);

  testcase("random_nonquadratic", "random_nonquadratic", []()
           { make_testcase_input(20, 25); });
  testcase("random_row", "random_row", []()
           { make_testcase_input(1, 500); });
  testcase("random_column", "random_column", []()
           { make_testcase_input(500, 1); });
  testcase("random_quadratic", "random_quadratic", []()
           { make_testcase_input(500, 500); });

  return 0;
}
