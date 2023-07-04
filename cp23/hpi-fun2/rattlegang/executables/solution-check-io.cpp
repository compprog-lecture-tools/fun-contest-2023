#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    assert(6 <= n && n <= 10000);
    assert(n % 2 == 0);
    vector<int> cnt(n,0);

    for (int i = 0; i < 3 * n / 2; i++) {
        int a,b; cin >> a >> b;
        assert(1 <= a && a <= n/2);
        assert(n/2 + 1 <= b && b <= n);
        cnt[a-1]++;
        cnt[b-1]++;
    }

    for (int i = 0; i < n; i++)
        assert(cnt[i] == 3);


    cout << n / 2 << endl;

    return 0;
}
