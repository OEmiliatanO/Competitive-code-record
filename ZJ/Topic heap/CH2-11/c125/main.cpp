#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
typedef struct _point
{
    int x,y;
    double Getdis(const _point &a){return sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));}
}stone;
stone Map[201];
int n;
double dis[201];
bool vis[201];
double spfa(void);
int main()
{
    for(int t=1;scanf("%d",&n)!=EOF&&n;t++)
    {
        for(int i=0;i<n&&scanf("%d %d",&Map[i].x,&Map[i].y);i++);
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",t,spfa());
    }
    return 0;
}
double spfa()
{
    queue<int> qu;
    int node;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<n;i++) dis[i]=1e9;
    dis[0]=0;
    vis[0]=true;
    qu.push(0);
    while(!qu.empty())
    {
        node=qu.front(),qu.pop();
        vis[node]=false;
        for(int i=1;i<n;i++)
        {
            double maxx=max(dis[node],Map[node].Getdis(Map[i]));
            if(maxx<dis[i])
            {
                dis[i]=maxx;
                if(!vis[i]) qu.push(i),vis[i]=true;
            }
        }
    }
    return dis[1];
}
