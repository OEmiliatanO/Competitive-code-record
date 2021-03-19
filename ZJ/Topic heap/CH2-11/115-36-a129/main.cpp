#include <cstdio>
#include <vector>
#include <algorithm>
#define min(x,y) (x)<(y)?(x):(y)
using namespace std;
typedef unsigned long long uint64;
const int MAXN=100000;
typedef struct _road
{
    int from,to,wi;
}road;
vector<road> v(200000);
int fa[MAXN],p=0,temproot1,temproot2;
uint64 ans=0;
bool cmp(const road &a,const road &b)
{
    return a.wi<b.wi;
}
int _find(int i)
{
    if(fa[i]==i) return i;
    else return fa[i]=_find(fa[i]);
}
int main()
{
    for(int n,m,cnt=0;scanf("%d %d",&n,&m)!=EOF;ans=0,p=0,cnt=0)
    {
        v.clear();
        for(int i=0;i<n;fa[i]=i,i++);
        for(int t=0,i,j,c;t<m&&scanf("%d %d %d",&i,&j,&c);p++,t++)
            v[p].from=i,v[p].to=j,v[p].wi=c;
        sort(v.begin(),v.begin()+p,cmp);
        for(int i=0;i<p;i++)
        {
            temproot1=_find(v[i].from),temproot2=_find(v[i].to);
            if(temproot1!=temproot2)
                fa[temproot1]=temproot2,ans+=v[i].wi,cnt++;
        }
        if(cnt>=n-1) printf("%llu\n",ans);
        else printf("-1\n");
    }
    return 0;
}
