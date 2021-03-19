#include <cstdio>
using namespace std;
typedef long long LL;
int main()
{
    for(LL N;scanf("%lld",&N)!=EOF;)
        if(N<0) printf("%lld\n",(0-N)*2);
        else printf("%lld\n",N*2-1);
    return 0;
}
