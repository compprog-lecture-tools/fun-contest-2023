#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct
{
    ll x;
    ll y;
    ll z;
} Cube;

vector<Cube> cubes;

static bool adjacent(Cube a, Cube b)
{
    return (abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z)) == 1;
}

static ll getSurfaceArea()
{
    ll total = 6 * cubes.size();
    for (int i = 0; i < cubes.size(); i++)
        for (int j = i + 1; j < cubes.size(); j++)
            if (adjacent(cubes[i], cubes[j]))
                total -= 2;

    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        Cube cube;
        cin >> cube.x >> cube.y >> cube.z;
        cubes.push_back(cube);
    }

    cout << getSurfaceArea() << endl;

    return 0;
}
