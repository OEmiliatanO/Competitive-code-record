#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int64;
double facet(int n)
{
    return ((0.5*log(2.0*n*acos(-1.0))+n*log(n+0.0)-n)/log(10.0));
}
int main()
{
    for(int64 n,k;scanf("%lld %lld",&n,&k)!=EOF;)
        printf("%lld\n",(n==k?1:(int64)floor((facet(n)-facet(k)-facet(n-k)+1))));
    return 0;
}
