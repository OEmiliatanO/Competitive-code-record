#include <cstdio>
#define min(x,y) ((x)>(y)?(y):(x))
using namespace std;
const int INF=0x3f3f3f,MAXN=102;
int N,M,t=1,Map[MAXN][MAXN];
int main()
{
    while(~scanf("%d %d",&N,&M))
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<M&&scanf("%d",&Map[i][j]);j++)
                Map[i][j]+=(i||j)*min((i?Map[i-1][j]:INF),(j?Map[i][j-1]:INF));
        printf("Case #%d :\n%d\n",t++,Map[N-1][M-1]);
    }
    return 0;
}
