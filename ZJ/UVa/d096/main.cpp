#include <cstdio>
using namespace std;
int main()
{
    long long n;
    while(~scanf("%lld",&n))
    {
        n=((n-1)>>1)+1;
        n*=n;n<<=1;
        long long r=n-1+n-3+n-5;
        printf("%lld\n",r);
    }
    return 0;
}
