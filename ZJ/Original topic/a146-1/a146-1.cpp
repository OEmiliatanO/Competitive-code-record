// a146-1.cpp
#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 1e6;

using pii = pair<int, int>;

int n, l;
int arr[MAXN + 10];
pii MinQu[MAXN + 10], MaxQu[MAXN + 10];
pii MinQu_idx, MaxQu_idx;

int ans[2][MAXN + 10], idx;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    while (cin >> n >> l)
    {

        if (l > n) l = n;

        MinQu_idx.first = MinQu_idx.second = 0;
        MaxQu_idx.first = MaxQu_idx.second = 0;

        idx = 0;

        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }

        for (int i = 1; i <= l; ++i)
        {
            while (MinQu_idx.second - MinQu_idx.first > 0 and MinQu[MinQu_idx.first].second <= i - l)
                MinQu_idx.first++;
            while (MinQu_idx.second - MinQu_idx.first > 0 and MinQu[MinQu_idx.second - 1].first > arr[i])
                MinQu_idx.second--;

            MinQu[MinQu_idx.second].first = arr[i], MinQu[MinQu_idx.second++].second = i;


            while (MaxQu_idx.second - MaxQu_idx.first > 0 and MaxQu[MaxQu_idx.first].second <= i - l)
                MaxQu_idx.first++;
            while (MaxQu_idx.second - MaxQu_idx.first > 0 and MaxQu[MaxQu_idx.second - 1].first < arr[i])
                MaxQu_idx.second--;

            MaxQu[MaxQu_idx.second].first = arr[i], MaxQu[MaxQu_idx.second++].second = i;
        }

        ans[0][idx] = MinQu[MinQu_idx.first].first;
        ans[1][idx] = MaxQu[MaxQu_idx.first].first;
        idx++;

        for (int i = l + 1; i <= n; ++i)
        {
            while (MinQu_idx.second - MinQu_idx.first > 0 and MinQu[MinQu_idx.first].second <= i - l)
                MinQu_idx.first++;
            while (MinQu_idx.second - MinQu_idx.first > 0 and MinQu[MinQu_idx.second - 1].first > arr[i])
                MinQu_idx.second--;

            MinQu[MinQu_idx.second].first = arr[i], MinQu[MinQu_idx.second++].second = i;
            

            while (MaxQu_idx.second - MaxQu_idx.first > 0 and MaxQu[MaxQu_idx.first].second <= i - l)
                MaxQu_idx.first++;
            while (MaxQu_idx.second - MaxQu_idx.first > 0 and MaxQu[MaxQu_idx.second - 1].first < arr[i])
                MaxQu_idx.second--;

            MaxQu[MaxQu_idx.second].first = arr[i], MaxQu[MaxQu_idx.second++].second = i;


            ans[0][idx] = MinQu[MinQu_idx.first].first;
            ans[1][idx] = MaxQu[MaxQu_idx.first].first;
            idx++;
        }

        for (int i = 0; i < idx; ++i)
            cout << ans[0][i] << " \n"[idx - 1 == i];
        for (int i = 0; i < idx; ++i)
            cout << ans[1][i] << " \n"[idx - 1 == i];
    }

    return 0;
}
