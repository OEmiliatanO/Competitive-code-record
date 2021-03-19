#include <cstdio>
using namespace std;
int context[1000000];
typedef long long LL;
int main()
{
    LL cnt=0,mood=0;
    for(int n;scanf("%d",&n)!=EOF&&n>0;mood=0,cnt=0)
    {
        for(int i=0;i<n&&scanf("%d",&context[i]);i++);
        for(int i=n-1;i>=0;i--)
        {
            if(context[i]<0)
            {
                mood+=context[i];
                cnt+=n-i;
            }
            else
            {
                LL sum=0;
                for(int j=i;j<n&&mood<0;j++)
                {
                    sum+=context[j];
                    if(sum+mood>0)
                        break;
                    if(sum<0)
                    {
                        cnt+=n-j;
                        break;
                    }
                }
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
