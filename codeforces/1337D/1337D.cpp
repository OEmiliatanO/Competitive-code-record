// 1337D.cpp
#include <iostream>
#include <algorithm>
#include <cstdint>
#include <climits>

using namespace std;

using int64 = long long;

constexpr int MAXN = 1e5;

int t;
int64 n[3];
int64 arr[3][MAXN + 1];

int64 ans = INT64_MAX;

int64 f(int x, int y, int z)
{
    return 1LL * (x - y) * (x - y) + 1LL * (y - z) * (y - z) + 1LL * (x - z) * (x - z);
}

void solve(int a, int b, int c)
{
    for (int i = 0; i < n[a]; ++i)
    {
        int posb = lower_bound(arr[b], arr[b] + n[b], arr[a][i]) - arr[b];
        int posc = upper_bound(arr[c], arr[c] + n[c], arr[a][i]) - arr[c];

        if (posb == n[b] || posc == 0) continue;

        --posc;
        ans = min(ans, f(arr[a][i], arr[b][posb], arr[c][posc]));
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        ans = INT64_MAX;

        cin >> n[0] >> n[1] >> n[2];

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < n[i]; ++j)
                cin >> arr[i][j];

        for (int i = 0; i < 3; ++i)
            sort(arr[i], arr[i] + n[i]);

        solve(0, 1, 2); solve(0, 2, 1);
        solve(1, 0, 2); solve(1, 2, 0);
        solve(2, 0, 1); solve(2, 1, 0);

        cout << ans << '\n';
    }

    return 0;
}
