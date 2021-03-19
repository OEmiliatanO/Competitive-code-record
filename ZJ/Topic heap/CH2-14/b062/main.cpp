#include <cstdio>
#include <cstring>
using namespace std;
int m,i,j,N,ans,DP[51][33][33];
bool Map[33][33];
char tmp;
int main()
{
    while(~scanf("%d",&m)&&getchar())
    {
        ans=0;
        memset(Map,false,sizeof(Map));
        memset(DP,0,sizeof(DP));
        for(int a=1;a<=m;getchar(),a++)
            for(int b=1;b<=m&&scanf("%c",&tmp);b++)
                Map[a][b]=DP[1][a][b]=tmp-'0';
        scanf("%d %d %d",&i,&j,&N);
        for(int k=1;k<=N;k++)
            for(int a=1;a<=m;a++)
                for(int b=1;b<=m;b++)
                    for(int c=1;c<=m;c++)
                        if(Map[a][c])
                            DP[k][a][b]+=DP[k-1][c][b];
        for(int Ni=1;Ni<=N;Ni++)
            ans+=DP[Ni][i][j];
        printf("%d\n",ans);
    }
    return 0;
}
