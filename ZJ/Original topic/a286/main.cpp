#include <cstdio>
#include <algorithm>

using namespace std;

typedef short int16;
typedef unsigned short uint16;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef pair<int, int> pii;

int me, tmp, n, now, ans, a, b ,c;

inline int fun(int x)
{
    while(x / 10)
    {
        tmp = 0;
        while(x)
            tmp += x % 10, x /= 10;
        x = tmp;
    }
    return x;
}

int main()
{
    while(~scanf("%d %d %d", &a, &b, &c))
    {

        now = 100000;

        me = fun(fun(a) + fun(b) + fun(c));

        scanf("%d", &n);

        for(int i = 1; i <= n && scanf("%d %d %d", &a, &b, &c); ++i)
        {
            tmp = fun(fun(a) + fun(b) + fun(c));


            if(abs(tmp - me) < now)
                now = abs(tmp - me), ans = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}
