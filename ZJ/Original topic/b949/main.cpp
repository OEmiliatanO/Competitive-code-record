#include <cstdio>

using namespace std;

unsigned long long m;

int main()
{
     while(~scanf("%llu", &m) && (m *= m))
           printf("%llu\n", (m << 4) + (m << 3) + m);
     return 0;
}
