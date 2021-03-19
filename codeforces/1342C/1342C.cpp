// 1342C.cpp
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

using int64 = long long;

int64 gcd(int64 a, int64 b)
{
    return b ? gcd(b, a % b) : a;
}

int t, q;
int64 a, b, lcm;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> q;

        if (a > b) swap(a, b);

        lcm = a * b / gcd(a, b);

        for (int i = 0; i < q; ++i)
        {
            int64 ans = 0;
            int64 l, r;
            cin >> l >> r;

            int64 tmp1 = l / lcm;
            int64 tmp2 = r / lcm;
            
            tmp2 += tmp2 * lcm <= r;

            if (tmp1 * lcm + b - 1 >= r)
                ans += r - l + 1;
            else
            {
                ans += max(0LL, ((tmp2 - 2) - (tmp1 + 1) + 1) * b);
                
                ans += max(0LL, b - (l - tmp1 * lcm));
                
                if (tmp1 + 1 <= tmp2 - 1)
                    ans += min(b, (r - (tmp2 - 1) * lcm + 1));
            }

            cout << r - l + 1 - ans << ' ';
        }

        cout << '\n';
    }
    return 0;
}
