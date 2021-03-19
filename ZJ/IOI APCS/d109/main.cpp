#include <cstdio>
#include <cstring>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
int DP[51][51][51][51];
int n,m,stu[51][51],maxi,tmp;
int main()
{
    while(~scanf("%d",&n))
    {
    memset(DP,0x80,sizeof(int)*51*51*51*51);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&stu[i][j]);
    DP[1][1][1][1]=stu[1][1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                for(int l=1;l<=n;l++)
                {
                    if(DP[i][j][k][l]!=0x80808080) continue;
                    if(DP[i-1][j][k-1][l]!=0x80808080) DP[i][j][k][l]=max(DP[i][j][k][l],DP[i-1][j][k-1][l]);
                    if(DP[i-1][j][k][l-1]!=0x80808080) DP[i][j][k][l]=max(DP[i][j][k][l],DP[i-1][j][k][l-1]);
                    if(DP[i][j-1][k-1][l]!=0x80808080) DP[i][j][k][l]=max(DP[i][j][k][l],DP[i][j-1][k-1][l]);
                    if(DP[i][j-1][k][l-1]!=0x80808080) DP[i][j][k][l]=max(DP[i][j][k][l],DP[i][j-1][k][l-1]);
                    DP[i][j][k][l]+=(i==k&&j==l?stu[i][j]:stu[i][j]+stu[k][l]);
                }
    printf("%d\n",DP[n][n][n][n]);
    }
    return 0;
}
