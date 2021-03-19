#include <cstdio>
#include <cstring>
#include <climits>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
const int MAXN=101;
int n,ans,sum,arr[MAXN][MAXN],colsum[MAXN][MAXN];
int main()
{
    while(~scanf("%d",&n))
    {
        ans=INT_MIN,sum=0;
        memset(colsum,0,sizeof(colsum));
        for(int i=1;i<=n;i++) for(int j=1;j<=n&&scanf("%d",&arr[i][j]);j++);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                colsum[i][j]=colsum[i-1][j]+arr[i][j];
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;sum=0,j++)
                for(int k=1;k<=n;k++)
                {
                    sum+=colsum[j][k]-colsum[i-1][k];
                    ans=max(ans,sum);
                    if(sum<0) sum=0;
                }
        printf("%d\n",ans);
    }
    return 0;
}
