#include <cstdio>
using namespace std;
int n,k,smokeass,ans;
int main()
{
    while(~scanf("%d %d",&n,&k))
    {
        ans=smokeass=0;
        while(n!=0)
        {
            ans+=n;
            smokeass+=n;
            n=smokeass/k;
            smokeass%=k;
        }
        printf("%d\n",ans);
    }
    return 0;
}
