// 1327B.cpp

#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAXN = 1e5;

int t;
int n;
bool prince[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(prince, false, sizeof(bool) * (MAXN + 1));

        int Unmarried = 0;

        for (int i = 1, k; i <= n; ++i)
        {
            bool flag = false;
            cin >> k;

            for (int j = 1, x; j <= k; ++j)
            {
                cin >> x;
                if (!prince[x] && !flag)
                    flag = prince[x] = true;
            }

            if (!flag)
                Unmarried = i;
        }

        if (Unmarried)
        {
            cout << "IMPROVE" << '\n';
            for (int i = 1; i <= n; ++i)
                if (!prince[i])
                {
                    cout << Unmarried << " " << i << '\n';
                    break;
                }
        }
        else
            cout << "OPTIMAL" << '\n';

    }

    return 0;
}
