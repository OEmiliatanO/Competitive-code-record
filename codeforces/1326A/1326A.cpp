// 1326A.cpp 

#include <iostream>

using namespace std;

int t;
int n;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << "-1" << '\n';
            continue;
        }

        for (int i = 1; i <= n - 2; ++i)
        {
            cout << '2';
        }

        if ((n - 1) * 2 % 3 == 0)
            cout << '4';
        else
            cout << '2';

        cout << '3' << '\n';
    }
}
