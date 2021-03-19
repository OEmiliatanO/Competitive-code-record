#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAXN = 5e4;

int t, n;

char ch;
char s[2][MAXN + 1];

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;
        bool flag = false;

        for (int i = 1; i <= n; ++i)
        {
            cin >> ch;
            if (flag)
            {
                s[0][i] = '0';
                s[1][i] = ch;
                continue;
            }

            if (ch == '2')
                s[0][i] = s[1][i] = '1';
            else if (ch == '0')
                s[0][i] = s[1][i] = '0';
            else
            {
                flag = true;
                s[0][i] = '1';
                s[1][i] = '0';
            }
        }

        s[0][n + 1] = s[1][n + 1] = 0;
        cout << s[0] + 1 << '\n' << s[1] + 1 << '\n';
    }

    return 0;
}
