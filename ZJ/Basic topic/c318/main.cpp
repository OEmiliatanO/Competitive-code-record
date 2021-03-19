#include <cstdio>
#include <queue>
#define Si first
#define Di second
using namespace std;
typedef pair<int,int> profit;
typedef priority_queue<profit> heap;
int T,N,s,d,ans;
profit tmp;
int main()
{
    ans=0;
    heap hp;
    scanf("%d %d",&N,&T);
    while(N--&&scanf("%d %d",&s,&d))
        hp.emplace(profit(s,d));
    while(T--&&hp.top().Si>0)
    {
        tmp=hp.top();
        hp.pop();
        ans+=(tmp.Si<0?0:tmp.Si);
        tmp.Si-=tmp.Di;
        hp.emplace(tmp);
    }
    printf("%d",ans);
    return 0;
}
