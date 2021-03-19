#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f
#define min(x,y) (x)>(y)?(y):(x)
#define max(x,y) (x)<(y)?(y):(x)
using namespace std;
struct Node
{
    int from,to,wi;
    Node(int a,int b,int c):from(a),to(b),wi(c){};
};
vector<Node> road;
int fa[10000],root1,root2;
int _find(int x)
{
    if(fa[x]==x) return x;
    else return fa[x]=_find(fa[x]);
}
bool cmp(const Node &a,const Node &b)
{
    return a.wi<b.wi;
}
int main()
{
    for(int N,M,ans=0;scanf("%d %d",&N,&M)!=EOF;ans=0)
    {
        for(int i=0;i<N;fa[i]=i,i++);
        for(int i=0,A,B,C;i<M&&scanf("%d %d %d",&A,&B,&C);i++)
            road.push_back(Node(A,B,C));
        sort(road.begin(),road.begin()+M,cmp);
        for(int i=0;i<M;i++)
        {
            root1=_find(road[i].from),root2=_find(road[i].to);
            if(root1!=root2)
                fa[root1]=root2,ans+=road[i].wi;
        }
        printf("%d\n",ans);
    }
    return 0;
}
