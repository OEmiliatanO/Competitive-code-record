#include <cstdio>
#include <cmath>
using namespace std;
typedef unsigned long long uint64;
int main()
{
    for(uint64 n;scanf("%llu",&n)!=EOF&&n;printf("%llu\n",(uint64)log2(n)+1));
    return 0;
}
