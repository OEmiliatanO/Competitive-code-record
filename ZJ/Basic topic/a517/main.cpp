#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include <cstdio>
#define min(x, y) ((x) > (y) ? (y) : (x))
#define minest(x, y, z) (min((x), min((y), (z))))

using namespace std;

typedef unsigned long long uint64;
uint64 X, Y, Z;

int main()
{
    while(~scanf("%llu %llu %llu", &X ,&Y, &Z))
        printf("%llu\n", X + Y + Z - (minest(X, Y, Z) << 1));
    return 0;
}
