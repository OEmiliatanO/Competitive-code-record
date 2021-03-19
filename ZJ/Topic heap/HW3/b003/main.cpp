#include <cstdio>

using namespace std;
typedef long long int64;
int main()
{
    for(int64 n,sum=0,cnt=0;scanf("%lld",&n)!=EOF;sum=0,cnt=0)
    {
        if(n<0) n=(~n)+1;
        while(sum<n) sum+=(++cnt);
        while((sum-n)&1) sum+=(++cnt);
        printf("%lld\n",cnt);
    }
    return 0;
}
