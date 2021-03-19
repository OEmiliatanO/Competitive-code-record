#include <cstdio>
using namespace std;
typedef unsigned int uint;
uint ans[21]={1};
int n;
int main()
{
    for(int i=1;i<=20;ans[i]=ans[i-1]<<1,i++);
    while(~scanf("%d",&n))
        for(int i=0;i<=n;printf("2^%d = %d\n",i,ans[i]),i++);
    return 0;
}
