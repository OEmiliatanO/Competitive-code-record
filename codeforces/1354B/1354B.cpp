// 1354B.cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int main()
{
    string s;
    int t;
    cin >> t;

    while (t--)
    {
        cin >> s;

        int a = -1, b = -1, c = -1;
        int ans = INT_MAX;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '1')
                a = i;
            else if (s[i] == '2')
                b = i;
            else
                c = i;

            if (a != -1 && b != -1 && c != -1)
                ans = min(ans, max({ a, b, c }) - min({ a, b, c }) + 1);
        }

        cout << (ans != INT_MAX ? ans : 0) << '\n';
    }


    return 0;

}
