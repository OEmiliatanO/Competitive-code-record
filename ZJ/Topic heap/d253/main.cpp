#include <cstdio>
#include <cstring>
#define min(x,y) ((x)>(y)?(y):(x))
using namespace std;
int n;
int cent[5]={1,5,10,25,50},ans[7491];
int main()
{
    ans[0]=1;
    for(int i=0;i<5;i++)
        for(int j=0;j+cent[i]<=7490;j++)
            ans[j+cent[i]]+=ans[j];
    while(~scanf("%d",&n)) printf("%d\n",ans[n]);
    return 0;
}
