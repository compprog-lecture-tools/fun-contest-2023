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

static bool adjacentZ(Cube a, Cube b)
{
    return (a.x == b.x && a.y == b.y && abs(a.z - b.z) == 1);
}

static bool adjacentY(Cube a, Cube b)
{
    return (a.x == b.x && abs(a.y - b.y) == 1 && a.z == b.z);
}

static bool adjacentX(Cube a, Cube b)
{
    return (abs(a.x - b.x) == 1 && a.y == b.y && a.z == b.z);
}

static ll getSurfaceArea()
{
    ll total = 6 * cubes.size();

    // sort cubes after x, y, z
    sort(cubes.begin(), cubes.end(), [](Cube a, Cube b) {
        if (a.x != b.x)
            return a.x < b.x;
        if (a.y != b.y)
            return a.y < b.y;
        return a.z < b.z;
    });

    for (int i = 0; i < cubes.size() - 1; i++)
        if (adjacentZ(cubes[i], cubes[i + 1]))
            total -= 2;

    // sort cubes after y, z, x
    sort(cubes.begin(), cubes.end(), [](Cube a, Cube b) {
        if (a.y != b.y)
            return a.y < b.y;
        if (a.z != b.z)
            return a.z < b.z;
        return a.x < b.x;
    }); 

    for (int i = 0; i < cubes.size() - 1; i++)
        if (adjacentX(cubes[i], cubes[i + 1]))
            total -= 2;

    // sort cubes after z, x, y
    sort(cubes.begin(), cubes.end(), [](Cube a, Cube b) {
        if (a.z != b.z)
            return a.z < b.z;
        if (a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    });

    for (int i = 0; i < cubes.size() - 1; i++)
        if (adjacentY(cubes[i], cubes[i + 1]))
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
