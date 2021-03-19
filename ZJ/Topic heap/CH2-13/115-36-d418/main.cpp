#include <cstdio>
using namespace std;
int main()
{
    int n,ans=0;scanf("%d",&n);
    for(int N;n--&&scanf("%d",&N);ans=0)
    {
        if(N==1) puts("1");
        else
        {
            for(int i=9,p=1;N&&i>=2;i--)
                for(;N%i==0;N/=i,p*=10) ans=ans+i*p;
            if(N!=1) puts("-1");
            else printf("%d\n",ans);
        }
    }
    return 0;
}
