#include <cstdio>
#include <algorithm>

using namespace std;

typedef short int16;
typedef unsigned short uint16;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef pair<int, int> pii;

uint64 n, f, a, b, c, sum;

int main()
{
    while(~scanf("%llu", &n))
    {
        while(n--)
        {
            sum = 0;
            scanf("%llu", &f);
            while(f-- && scanf("%llu %llu %llu", &a, &b, &c))
                sum += a * c;
            printf("%llu\n", sum);
        }
    }
    return 0;
}
