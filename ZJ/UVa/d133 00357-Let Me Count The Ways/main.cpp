#include <cstdio>
#include <cassert>
using namespace std;
typedef long long int64;
int n,cent[5]={1,5,10,25,50};
int64 ans[30001]{1};
int main()
{
    for(int i=0;i<5;i++)
        for(int j=cent[i];j<30001;j++)
            ans[j]+=ans[j-cent[i]];
    while(~scanf("%d",&n))
        if(ans[n]==1)
            printf("There is only 1 way to produce %d cents change.\n",n);
        else
            printf("There are %lld ways to produce %d cents change.\n",ans[n],n);
    return 0;
}
