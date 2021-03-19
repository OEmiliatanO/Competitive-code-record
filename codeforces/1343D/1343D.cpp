// 1343D.cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

using int64 = long long;

constexpr int MAXN = 2e5;

int t, n, k;
int arr[MAXN + 1], S[2 * (MAXN + 1)], cnt[2 * (MAXN + 1)];

int main()
{
    cin >> t;

    while (t--)
    {
        memset(S, 0, sizeof(int) * 2 * (MAXN + 1));
        memset(cnt, 0, sizeof(int) * 2 * (MAXN + 1));

        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];

        for (int i = 1; i <= n / 2; ++i)
        {
            ++cnt[arr[i] + arr[n - i + 1]];

            int l = min(arr[i], arr[n - i + 1]);
            int r = max(arr[i], arr[n - i + 1]);
            l += 1; r += k;

            ++S[l], --S[r + 1];
        }

        for (int i = 2; i <= 2 * k + 1; ++i)
            S[i] += S[i - 1];

        int ans = INT_MAX;
        for (int i = 2; i <= 2 * k + 1; ++i)
            ans = min(ans, S[i] - cnt[i] + (n / 2 - S[i]) * 2);

        cout << ans << '\n';
    }

    return 0;
}
