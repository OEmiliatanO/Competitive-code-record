#include <cstdio>
#include <string.h>
using namespace std;
int girlfriend[50001];
//int girlFansCnt[50001];
int relation[50001];
int _find(int n)
{
    if(n==relation[n]) return n;
    else return relation[n]=_find(relation[n]);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0,N,M;t<T&&scanf("%d %d",&N,&M);t++)
    {
        //memset(girlFansCnt,0,sizeof(girlFansCnt));
        memset(girlfriend,0,sizeof(girlfriend));
        for(int i=1;i<=N;i++) relation[i]=i;
        for(int i=1,in;i<=N&&scanf("%d",&in);i++)
        {
            girlfriend[i]=in;
            //girlFansCnt[in]++;
        }
        for(int i=0,ans=0,x,y;i<M&&scanf("%d %d",&x,&y);ans=0,i++)
        {
            int xroot=_find(x),yroot=_find(y);
            relation[xroot]=yroot;
            for(int j=1;j<=N;j++)
                if(relation[j]==yroot&&girlfriend[yroot]==girlfriend[j]) ans++;
            printf("ans=%d\n",ans);
        }
    }
    return 0;
}
