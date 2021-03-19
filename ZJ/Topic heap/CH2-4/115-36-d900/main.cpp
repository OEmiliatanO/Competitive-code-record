#include <cstdio>
#include <queue>
#define max(x,y) (x)>(y)?(x):(y)
using namespace std;
int main()
{
    int n,m,ans=0;scanf("%d %d",&n,&m);
    priority_queue<int,vector<int>,greater<int> > qu;
    for(int i=0;i<m;i++) qu.push(0);
    for(int i=0,wi;i<n&&scanf("%d",&wi);i++)
    {
        wi+=qu.top();qu.pop();
        ans=max(wi,ans);
        qu.push(wi);
    }
    printf("%d\n",ans);
    return 0;
}
