#include <cstdio>
#include <cstring>
using namespace std;
int sum[501][501],in;
int main()
{
    for(int n,m;~scanf("%d %d",&n,&m);)
    {
        memset(sum[0],0,sizeof(sum[0]));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n&&scanf("%d",&in);j++)
                sum[i][j]=in+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        for(int i=0,x1,x2,y1,y2;i<m&&scanf("%d %d %d %d",&x1,&y1,&x2,&y2);i++)
            printf("%d\n",sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1]);
    }
    return 0;
}
