// 1326B.cpp

#include <iostream>
#include <algorithm>

using namespace std;

using int64 = long long;

constexpr int MAXN = 2e5;

int n;
int64 b[MAXN + 1];
int64 Nmax = -1;

int main()
{
    cin >> n;

    cin >> b[1];
    Nmax = b[1];
    cout << Nmax << ' ';

    for (int i = 2; i <= n; ++i)
    {
        cin >> b[i];
        cout << b[i] + Nmax << ' ';
        Nmax = max(Nmax, b[i] + Nmax);
    }

    return 0;
}
