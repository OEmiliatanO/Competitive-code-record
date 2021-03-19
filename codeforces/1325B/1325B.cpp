// 1325B.cpp
#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 1e5;

int t, n, arr[MAXN + 1];

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; ++i) cin >> arr[i];

        sort(arr, arr + n);
        int len = unique(arr, arr + n) - arr;
        
        cout << min(len, n) << '\n';
    }

    return 0;
}
