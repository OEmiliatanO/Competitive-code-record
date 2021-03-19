#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct _point
{
    int x,y;
}point;
bool cmp(const point &a,const point &b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
point P[500000];
vector<point> ans;
int main()
{
    for(int t=1,n,x,y,maxy=-1,cnt=0;scanf("%d",&n)!=EOF;maxy=-1,cnt=0,ans.clear(),t++)
    {
        for(int i=0;i<n&&scanf("%d %d",&P[i].x,&P[i].y);i++);
        sort(P,P+n,cmp);
        for(int i=n-1;i>=0;i--)
            if(P[i].y>maxy)
            {
                cnt++;
                maxy=P[i].y;
                ans.push_back(P[i]);
            }
        printf("Case %d:\n",t);
        printf("Dominate Point: %d\n",ans.size());
        for(int i=ans.size()-1;i>=0;i--)
            printf("(%d,%d)\n",ans[i].x,ans[i].y);
    }
    return 0;
}
