#include <cstdio>
using namespace std;
unsigned long long n,m;
int main()
{
    while(~scanf("%llu %llu",&n,&m)) printf("%llu\n",n*(n+1)*m*(m+1)>>2);
    return 0;
}
