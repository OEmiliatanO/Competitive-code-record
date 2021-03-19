// 1348C.cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int t;
int n, k;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cin >> s;

        sort(s.begin(), s.end());

        if (k == 1)
            cout << s << '\n';
        else
            if (s[0] == s[k - 1])
            {
                cout << s[0];
                if (s[k] == s[n - 1])
                {
                    for (int i = 0; i < (n - k) / k; ++i)
                        cout << s[k];
                    if ((n - k) % k != 0)
                        cout << s[k];
                }
                else
                    for (int i = k; i < n; ++i)
                        cout << s[i];

                cout << '\n';
            }
            else
                cout << s[k - 1] << '\n';
    }


    return 0;
}
