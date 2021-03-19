#include <cstdio>
#include <utility>
using namespace std;
int T,N,S,x,y,p,ans;
pair<int,int> arr[5001];
int main()
{
    scanf("%d",&T);
    while(T--&&scanf("%d %d",&N,&S))
    {
        p=ans=0;
        while(N--&&scanf("%d %d",&x,&y))
            arr[p++]=make_pair(x,y);
        scanf("%d %d",&x,&y);
        for(int i=0;i<p;i++)
            ans+=(S*S>=(x-arr[i].first)*(x-arr[i].first)+(y-arr[i].second)*(y-arr[i].second));
        printf("%d\n",ans);
    }
    return 0;
}
