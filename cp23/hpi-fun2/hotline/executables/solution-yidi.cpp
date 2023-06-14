#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << #x << "]: " << (x) << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l, r;
    cin >> l >> r;

    for (int i=l; i<=r; i++) {
        int x = i;

        bool a[10] = {};
        bool flag = true;

        while (x > 0 && flag) {
            if (a[x%10]) flag = false;
            a[x%10] = true;
            x /= 10;
        }

        if (flag) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}
