#include <cstdio>
#include <cstring>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
int n,pole_N,t;
int tot[1001]={0},len[21];
int main()
{
    scanf("%d",&t);
    while(t--&&scanf("%d",&n))
    {
        memset(tot,0,sizeof(tot));
        scanf("%d",&pole_N);
        for(int i=1;i<=pole_N&&scanf("%d",&len[i]);i++);
        for(int i=1;i<=pole_N;i++)
            for(int j=n;j>=len[i];j--)
            {
                tot[j]=max(tot[j-len[i]]+len[i],tot[j]);
                if(tot[n]==n) break;
            }
        puts((tot[n]==n?"YES":"NO"));
    }
    return 0;
}
