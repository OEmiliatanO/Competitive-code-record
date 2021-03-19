// 1451 - Average.cpp
#pragma warning( disable : 4996 )
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

using pii = pair<int, int>;

constexpr int MAXN = 1e5;

int T, n, L;
char str[MAXN + 2];
int S[MAXN + 2]{};

int dq[MAXN + 2];
int head, tail;

int cmp(pii a, pii b)
{
    return (S[a.second] - S[a.first]) * (b.second - b.first) - (S[b.second] - S[b.first]) * (a.second - a.first);
}

int main()
{
    scanf("%d", &T);

    while (T--)
    {
        head = tail = 0;

        scanf("%d %d", &n, &L);
        scanf("%s", str + 1);

        for (int i = 1; i <= n; ++i)
            S[i] = S[i - 1] + str[i] - '0';

        int ansl = 0, ansr = L;
        for (int now = L; now <= n; ++now)
        {
            int dot = now - L;
            while (tail - head >= 2 && cmp({ dq[tail - 1], dot }, { dq[tail - 2], dot }) <= 0)
                --tail;

            dq[tail++] = dot;

            while (tail - head >= 2 && cmp({ dq[head], now }, { dq[head + 1], now }) <= 0)
                ++head;

            int cmpResult = cmp({ ansl, ansr }, { dq[head], now });
            if (cmpResult < 0 || (cmpResult == 0 && now - dq[head] < ansr - ansl))
                ansl = dq[head], ansr = now;
        }

        printf("%d %d\n", ansl + 1, ansr);
    }

    return 0;
}