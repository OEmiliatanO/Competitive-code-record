#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int,int> vec;
typedef long long int64;
vector<vec> Vect;
int a,b;
int64 ans=0;
int main()
{
    while(~scanf("%d:%d",&a,&b)&&a&&b)
        Vect.emplace_back(make_pair(a,b));
    while(~scanf("%d:%d",&a,&b)&&a&&b)
    {
        for(auto it:Vect)
            if(it.first==a)
            {
                ans+=it.second*b;
                break;
            }
    }
    printf("%lld",ans);
    return 0;
}
