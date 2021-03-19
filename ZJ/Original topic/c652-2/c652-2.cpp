// c652-2.cpp
#pragma warning( disable : 4996 )
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <utility>
#include <cassert>
#include <fstream>

using namespace std;

constexpr int MAXN = 3e5;

int64_t a[MAXN + 1]{}, block[550]{};
pair<int, int> Binv[550]{};

int n, q, op, l ,r;
int totBk;

fstream in;

int main()
{
    //in.open("17.in", ios::in);

    //in >> n >> q;

    scanf("%d %d", &n, &q);

    totBk = n / sqrt(n);
    
    for (int i = 1, bn; i <= n; ++i)
    {
        //in >> a[i];
        scanf("%lld", &a[i]);

        bn = i / totBk + 1;
        block[bn] += a[i];
        Binv[bn].first = Binv[bn].first ? Binv[bn].first : i;
        Binv[bn].second = max(Binv[bn].second, i);
    }

    Binv[n / totBk + 2].first = INT32_MAX;

    while (q--)
    {
        //in >> op >> l >> r;
        scanf("%d %d %d", &op, &l, &r);
        
        //cout << q << '\n';

        if (op == 0)
        {
            int st = l / totBk + 1, ed = r / totBk + 1;
            int64_t res = 0;
            
            if (st != ed)
            {
                for (int i = st + 1; i <= ed - 1; ++i)
                    res += block[i];

                if (block[st] == 1LL * (1LL + Binv[st].second - Binv[st].first))
                    res += 1LL + Binv[st].second - l;
                else
                    for (int i = l; i < Binv[st + 1].first; ++i)
                        res += a[i];

                if (block[ed] == 1LL * (1LL + Binv[ed].second - Binv[ed].first))
                    res += 1LL + r - Binv[ed].first;
                else
                    for (int i = Binv[ed].first; i <= r; ++i)
                        res += a[i];
            }
            else
            {
                if (block[st] == 1LL * (1LL + Binv[st].second - Binv[st].first)) 
                    res = 1LL + r - l;
                else
                    for (int i = l; i <= r; ++i)
                        res += a[i];
            }

            printf("%lld\n", res);
        }
        else
        {
            int st = l / totBk + 1, ed = r / totBk + 1;

            if (st != ed)
            {
                for (int i = l, bn; i <= r;)
                {
                    bn = i / totBk + 1;
                    if (block[bn] == 1LL * (1LL + Binv[bn].second - Binv[bn].first))
                        i = Binv[bn + 1].first;
                    else
                        for (; i <= Binv[bn].second && i <= r; ++i)
                        {
                            block[bn] -= a[i];
                            a[i] = sqrt(a[i]);
                            block[bn] += a[i];
                        }
                }
            }
            else
            {
                if (block[st] == 1LL * (1LL + Binv[st].second - Binv[st].first)) continue;

                for (int i = l; i <= r; ++i)
                {
                    block[st] -= a[i];
                    a[i] = sqrt(a[i]);
                    block[st] += a[i];
                }
            }
        }
    }

    return 0;
}
