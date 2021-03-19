// 1342D.cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

constexpr int MAXN = 2e5;

int n, k;
int m[MAXN + 1], c[MAXN + 1], cnt[MAXN + 2];
int t;
int len[MAXN + 1];
vector<int> a[MAXN + 1];

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        cin >> m[i];
        ++cnt[m[i]];
    }
    for (int i = 1; i <= k; ++i)
    {
        cin >> c[i];
        cnt[i] += cnt[i - 1];
    }

    t = -1;
    for (int i = 1; i <= k; ++i)
        t = max(t, (cnt[k] - cnt[i - 1]) / c[i] + !!((cnt[k] - cnt[i - 1]) % c[i]));

    sort(m + 1, m + 1 + n, greater<int>());
    for (int i = 1, j = 1; i <= n; ++i)
    {
        a[j].emplace_back(m[i]);
        j = j % t + 1;
    }

    cout << t << '\n';
    for (int i = 1; i <= t; ++i)
    {
        cout << a[i].size();
        for (auto it : a[i])
            cout << " " << it;
        cout << '\n';
    }

    return 0;
}
