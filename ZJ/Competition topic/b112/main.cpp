#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    for(int N,ans;scanf("%d",&N)!=EOF&&N;printf("%d\n",ans))
    {
        scanf("%d",&ans);
        for(int a,i=1;i<N&&scanf("%d",&a);ans=__gcd(a,ans),i++);
    }
    return 0;
}
