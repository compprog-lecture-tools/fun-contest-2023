#include <testlib.h>
#include <bits/stdc++.h>
#include <string_view>

using namespace std;


const string_view SAMPLE1 = R"(4 4
1 2
2 3
3 1
3 4
)";

const string_view SAMPLE2 = R"(5 4
1 2
2 3
3 4
4 5
)";

const string_view SAMPLE3 = R"(4 4
1 2
2 3
3 4
4 1
)";

const string_view PREDEFINED1 = R"(7 8
1 2
1 3
3 2
2 7
2 5
5 6
6 4
2 4
)";

const string_view PREDEFINED2 = R"(12 14
1 2
2 3
3 4
1 4
4 5
5 6
6 9
6 7
7 8
9 8
8 10
10 11
10 12
11 12
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


void printRandomGraph(int n, int m){
    set<pair<int, int>> edges;
    assert(m>=n-1);
    std::vector<int> unvisited(n);
    for(int i = 0; i < n; i++){
        unvisited[i] = i+1;
    }
    int u = rnd.next(1, n);

    vector<int> visited = {u};
    unvisited.erase(remove(unvisited.begin(), unvisited.end(), u), unvisited.end());

    // build tree to make graph connected
    for(int i=1; i<=n-1; i++){
        int unvisited_size = unvisited.size() - 1;
        int outside_idx = rnd.next(0, unvisited_size);

        int visited_size = visited.size() - 1;
        int inside_idx = rnd.next(0, visited_size);

        int u = visited[inside_idx];
        int v = unvisited[outside_idx];

        edges.insert(make_pair(u,v));
        println(u, v);

        //remove last visited value from unvisited values
        unvisited.erase(remove(unvisited.begin(), unvisited.end(), v), unvisited.end());
        visited.push_back(v);
    }

    int v;
    for(int i=n; i<=m; i++){
        u = rnd.next(1, n);
        v = rnd.next(1, n);
        if(u == v){
            i--; continue;
        }
        pair<int, int> edge = make_pair(u,v);
        pair<int, int> reversed_edge = make_pair(v,u);

        if(edges.count(edge) || edges.count(reversed_edge)){ // only add edge if it does not exist yet
            i--; continue;
        } else {
            edges.insert(make_pair(u,v));
            println(u, v);
        }
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(42);

    sample(1, SAMPLE1);
    sample(2, SAMPLE2);
    sample(3, SAMPLE3);
    predefined("pred1", "one bridge", PREDEFINED1);
    predefined("pred2", "bigger graph, multiple bridges", PREDEFINED2);
    const long long EDGE_MAX = 100000;
    const long long NODE_MAX = 50000;

    // Create random graphs of varying size
    for (int i = 1; i <= 10; i++) {
        testcase("random"+to_string(i), "random connected graph "+to_string(i), [&EDGE_MAX]{
            long long n = rnd.next(2ll, NODE_MAX/10);
            long long maximum_edge_amount = min((n*(n-1))/2, EDGE_MAX/10);

            long long m;
            if(n==2) m = 1;
            else{
                assert(n-1<maximum_edge_amount);
                m = rnd.next(n-1, maximum_edge_amount);
            }

            assert(n<=NODE_MAX); assert(n>=2);
            assert(m<=maximum_edge_amount); assert(m>=n-1);

            println(n, m);
            printRandomGraph(n, m);
        });
    }

    // Create random graphs of MAX size
    for (int i = 1; i <= 3; i++) {
        testcase("random_max_size"+to_string(i), "random graphs of max size", []{
            int n = NODE_MAX;
            int m = EDGE_MAX;

            println(n, m);
            printRandomGraph(n, m);
        });
    }

    return 0;
}