#include <cstdio>

using namespace std;

int N;
long long H(int n)
{
    long long res = 0;

    for( int i = 1; i <= n; i=i+1)
    {
        res = (res + n/i);
    }
    return res;
}

int main()
{
    while(~scanf("%d",&N))
        printf("%lld\n",H(N));
    return 0;
}
