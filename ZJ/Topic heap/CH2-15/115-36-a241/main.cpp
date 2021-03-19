#include <cstdio>
#include <algorithm>
#define min(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

typedef long long int64;

const int MAXN = 190000000;
int m, pos, num[220]{1}, nexindex = 1, i2 = 0, i5 = 0;
int64 n;

int main()
{
    while(nexindex < 212)
    {
        int a = min((num[i2] << 1), (num[i5] + (num[i5] << 2)));

        num[nexindex] = a;

        while((num[i2] << 1) <= num[nexindex])
            i2++;
        while((num[i5] + (num[i5] << 2)) <= num[nexindex])
            i5++;

        nexindex++;
    }

    scanf("%d",&m);
    while(m-- && scanf("%lld", &n))
    {
        pos = lower_bound(num, num + 213, n) - num;

        if(num[pos] > n) pos--;

        printf("%d\n", pos);
    }
    return 0;
}
