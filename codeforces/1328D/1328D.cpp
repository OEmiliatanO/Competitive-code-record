// 1328D.cpp
#include <iostream>
#include <set>

using namespace std;

constexpr int MAXN = 2e5;

set<int> S;

int q, n;
int t[MAXN + 1];
int ans[MAXN + 1];

int main()
{
    cin >> q;
    while (q--)
    {
        cin >> n;
        
        S.clear();

        for (int i = 0; i < n; ++i)
        {
            cin >> t[i];
            S.emplace(t[i]);
            ans[i] = (i & 1) + 1;
        }

        if (S.size() == 1)
        {
            cout << "1" << '\n';
            for (int i = 0; i < n; ++i)
                cout << '1' << ' ';
            cout << '\n';
            continue;
        }
        
        if ((n & 1) == 0)
        {
            cout << "2" << '\n';
            for (int i = 0; i < n; ++i)
                cout << ans[i] << ' ';
            cout << '\n';
            continue;
        }

        bool flag = false;
        for (int i = 0; i < n; ++i)
        {
            if (t[i] == t[(i + 1) % n])
            {
                flag = true;

                int pos = i + 1;
                for (int j = ans[i]; pos < n; ++pos, j = 3 - j)
                    ans[pos] = j;

                pos = i;
                for (int j = ans[i]; pos >= 0; --pos, j = 3 - j)
                    ans[pos] = j;
                
                cout << '2' << '\n';
                for (int i = 0; i < n; ++i)
                    cout << ans[i] << ' ';
                cout << '\n';
                break;
            }
        }

        if (!flag)
        {
            cout << '3' << '\n';
            ans[n - 1] = 3;
            for (int i = 0; i < n; ++i)
                cout << ans[i] << ' ';
            cout << '\n';
        }
    }

    return 0;
}
