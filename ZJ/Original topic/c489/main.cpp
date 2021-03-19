#include <cstdio>
#define max(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

const int undefine = -1;
int N, M, num, cnt[3]{0, 0}, chart[9][10]{}, index, a = undefine, b = undefine, ans = 0;

inline int _hash(int n)
{
    if(b == undefine && a != n) b = n;

    if(b != undefine && n == b) return 1;
    else if(n == a) return 0;

    return 2;
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &a); --N;

    ++cnt[_hash(a)];
    num = a, index = -1;
    while(num)
    {
        ++chart[++index][num % 10];
        num /= 10;
    }

    while(N-- && scanf("%d", &num))
    {
        ++cnt[_hash(num)];

        index = -1;
        while(num)
        {
            ++chart[++index][num % 10];
            num /= 10;
        }
    }

    M = max(cnt[0], cnt[1]);

    for(int i = 8; i >= 0; --i)
    {
        ans = (ans << 1) + (ans << 3);
        for(int j = 0; j < 10; ++j)
        {
            if(chart[i][j] % M)
            {
                ans += j;
                break;
            }
        }
    }

    printf("%d", ans);

    return 0;
}
