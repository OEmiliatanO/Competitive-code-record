#include <cstdio>
using namespace std;
typedef long long int64;
const int MAXN=200001;
int64 ans[MAXN]{},b[MAXN];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=(n>>1)&&scanf("%lld",&b[i]);i++);
    ans[n+1]=0x7f7f7f7f7f7f7f7f;
    for(int i=1;i<=(n>>1);i++)
    {
        ans[i]=ans[i-1];
        ans[n-i+1]=b[i]-ans[i];
        if(ans[n-i+1]>ans[n-i+2])
        {
            ans[n-i+1]=ans[n-i+2];
            ans[i]=b[i]-ans[n-i+1];
        }
    }
    for(int i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    return 0;
}
