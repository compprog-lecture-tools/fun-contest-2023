#include <bits/stdc++.h>
#include <vector>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using ld = long double;
using vld = vector<ld>;

struct UF {
    vector<int> par;
    UF(int n) : par(n) { iota(begin(par), end(par), 0); }
    int find(int i) { return par[i] == i ? i : par[i] = find(par[i]); }
    void join(int i, int j) { par[find(i)] = find(j); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n;
    cin >> n;
    vld x(n), y(n), r(n);
    rep(i, n) cin >> x[i] >> y[i] >> r[i];

    UF uf(n + 2);

    rep(i, n) {
        if (y[i] <= r[i])
            uf.join(i, n);
        if (y[i] + r[i] >= 10)
            uf.join(i, n + 1);
        rep(j, n) {
            if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= (r[i] + r[j]) * (r[i] + r[j]))
                uf.join(i, j);
        }
    }

    cout << (uf.find(n) != uf.find(n+1) ? "YES" : "NO") << endl;

    return 0;
}
