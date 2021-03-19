#include <cstdio>
#define max(x,y) (x)>(y)?(x):(y)
using namespace std;
int maxx=-1;
int main()
{
    for(int n;scanf("%d",&n)!=EOF&&n;maxx=-1)
    {
        for(int i=0,ai,real=0;i<n&&scanf("%d",&ai);i++,real=0)
        {
            while(ai!=0)
            {
                real=real*10+ai%10;
                ai/=10;
            }
            maxx=max(maxx,real);
        }
        printf("%d\n",maxx);
    }
    return 0;
}
