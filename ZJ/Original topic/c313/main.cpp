#include <cstdio>
#include <cstring>
#include <queue>
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
int Map[100001][100001],node;
int dis[100001];
bool vis[100001];
int spfa(int a,int b)
{
    queue<int> qu;
    memset(vis,false,sizeof(vis));
    memset(dis,0x3f,sizeo(dis));
    qu.push(a);
    vis[a]=true;
    dis[a]=0;
    while(!qu.empty())
    {
        node=qu.front(),qu.pop();
        vis[node]=false;
        for(int i=1;i<=n;i++)
        {
            int minx=min(dis[node],max(dis[node],Map[node][i]));
            if(minx>dis[node])
            {
                dis[node]=minx;
                if(!vis[i]) vis[i]=true,qu.push(i);
            }
        }
    }
    return dis[b];
}
int main()
{
    for(int n,q;scanf("%d",&n)!=EOF&&n;)
    {
        memset(Map,0x3f,sizeof(Map));
        for(int i=1;i<=n;i++) Map[i][i]=0;
        for(int i=1,x,y,d;i<=n-1&&scanf("%d %d %d",&x,&y,&d);i++)
            Map[x][y]=Map[y][x]=min(Map[x,y],d);
        for(int i=0,a,b;i<q&&scanf("%d %d",&a,&b);i++) printf("%d\n",spfa(a,b));
    }
    return 0;
}
