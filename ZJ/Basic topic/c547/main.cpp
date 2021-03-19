#include <cstdio>
#include <string.h>
using namespace std;
int ans[10002];
int main()
{
    memset(ans,0,sizeof(ans));
    ans[1]=1;
    ans[2]=2;
    for(int i=3;i<=10000;i++)
        ans[i]=(ans[i-1]+ans[i-2])%1000000007;
    for(int n;scanf("%d",&n)!=EOF;)
        printf("%d\n",ans[n]);
    return 0;
}
