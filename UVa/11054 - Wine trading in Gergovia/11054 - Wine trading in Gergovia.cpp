// 11054 - Wine trading in Gergovia.cpp

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

using int64 = long long;

int n;

int main()
{
    while (cin >> n && n)
    {
        int64 x, last = 0, ans = 0;

        while (n--)
        {
            cin >> x;
            last += x;
            ans += abs(last);
        }

        cout << ans << '\n';
    }

    return 0;
}