#include <cstdio>
#include <set>
#include <algorithm>
#define ALL(x) x.begin(),x.end()
using namespace std;
set<int> Set;
set<int>::iterator up,low;
int main()
{
    for(int n,sum;scanf("%d",&n)!=EOF&&n>0;sum,Set.clear())
    {
        int in;
        scanf("%d",&in);
        Set.insert(in);
        sum=in;
        for(int i=1;i<n&&scanf("%d",&in);i++,Set.insert(in))
        {
            low=Set.lower_bound(in);
            up=low;
            if(low!=Set.begin()) low--;
            if(up==Set.end()) sum+=in-*low;
            else sum+=min(abs(*up-in),abs(in-*low));
        }
        printf("%d\n",sum);
    }
    return 0;
}
