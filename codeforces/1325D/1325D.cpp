// 1325D.cpp
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

using int64 = long long;

int64 u, v;

int main()
{
    cin >> u >> v;

    if (u > v || (u & 1) != (v & 1)) return puts("-1"), 0;

    if (u == v)
    {
        if (!u)
            cout << "0";
        else
            cout << "1" << '\n' << u;
        return 0;
    }

    int64 x = (v - u) / 2;

    if ((x & u) == 0)
        cout << 2 << '\n' << (u | x) << " " << x;
    else
        cout << 3 << '\n' << u << " " << x << " " << x;
    
    return 0;
}
