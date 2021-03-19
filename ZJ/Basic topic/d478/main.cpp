#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
typedef long long LL;
set<LL> A;
int main()
{
    LL in;
    for(int n,m,cnt=0;scanf("%d %d",&n,&m)!=EOF;)
        for(int i=0;i<n;i++,cnt=0,A.clear())
        {
            for(int j=0;j<m&&scanf("%lld",&in);j++)
                A.insert(in);
            for(int j=0;j<m&&scanf("%lld",&in);j++)
            {
                auto it=A.lower_bound(in);
                if(*it==in) cnt++;
            }
            printf("%d\n",cnt);
        }
    return 0;
}
