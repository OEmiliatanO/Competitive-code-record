#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long int64;
int p,q,POW;
int64 Maxx=-1,minn=22222222222222223;
bool ans=false;
void dfs(int64 N,int nowp)
{
    if(nowp==p)
    {
        if(N%POW==0){Maxx=max(Maxx,N); minn=min(minn,N); ans=true;}
    }
    else
    {
        dfs(N*10+1,nowp+1);
        dfs(N*10+2,nowp+1);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;T--&&scanf("%d %d",&p,&q)!=EOF;t++,ans=false,Maxx=-1,minn=22222222222222223)
    {
        POW=pow(2,q);
        dfs(0,0);
        printf("Case %d: ",t);
        if(!ans) printf("impossible");
        else
        {
            printf("%lld",minn);
            if(minn!=Maxx) printf(" %lld",Maxx);
        }
        printf("\n");
    }
    return 0;
}
