// a191.cpp
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <algorithm>
#include <tuple>
#include <cstring>
using namespace std;

using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

constexpr int MAXN = 1e4;

int n;
tiii S[MAXN + 1];

int hexv[MAXN + 1], hexv_idx;
int ans[MAXN + 1];
int dq[2*(MAXN + 1)], tail, head;

int cross(pii v1, pii v2)
{
    return v1.first * v2.second - v1.second * v2.first;
}

void findhexv(bool lower = true)
{
    dq[tail++] = 1;
    dq[tail++] = 2;
    for (int i = 3; i <= n; ++i)
    {
        pii AB, BC;
        while (true)
        {
            AB = { get<0>(S[dq[tail - 1]]) - get<0>(S[dq[tail - 2]]), get<1>(S[dq[tail - 1]]) - get<1>(S[dq[tail - 2]]) };
            BC = { get<0>(S[i]) - get<0>(S[dq[tail - 1]]), get<1>(S[i]) - get<1>(S[dq[tail - 1]]) };

            if (((lower && cross(AB, BC) < 0) || (!lower && cross(AB, BC) > 0)) && tail - head > 1)
            {
                --tail;
                if (tail - head <= 1)
                    break;
            }
            else
                break;
        }
        dq[tail++] = i;
    }
}

int dis(int i, int j)
{
    return (get<0>(S[i]) - get<0>(S[j])) * (get<0>(S[i]) - get<0>(S[j])) + (get<1>(S[i]) - get<1>(S[j])) * (get<1>(S[i]) - get<1>(S[j]));
}

bool inhexv[MAXN + 1];

int main()
{
    while (cin >> n)
    {
        memset(ans, -1, sizeof(int) * (MAXN + 1));
        memset(inhexv, false, sizeof(bool) * (MAXN + 1));

        for (int i = 1; i <= n; ++i)
        {
            cin >> get<0>(S[i]) >> get<1>(S[i]);
            get<2>(S[i]) = i;
        }
        
        sort(S + 1, S + 1 + n);

        head = tail = 0;
        findhexv(true);

        hexv_idx = 0;
        for (int i = 0; i < tail; ++i)
        {
            if (!inhexv[dq[i]])
            {
                inhexv[dq[i]] = true;
                hexv[hexv_idx++] = dq[i];
            }
        }

        head = tail = 0;
        findhexv(false);

        for (int i = 0; i < tail; ++i)
        {
            if (!inhexv[dq[i]])
            {
                inhexv[dq[i]] = true;
                hexv[hexv_idx++] = dq[i];
            }
        }

        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < hexv_idx; ++j)
                ans[get<2>(S[i])] = max(ans[get<2>(S[i])], dis(i, hexv[j]));

        for (int i = 1; i <= n; ++i)
            cout << ans[i] << '\n';

    }

    return 0;
}