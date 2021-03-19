#include <cstdio>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
const int MAXN=101;
int n,t,arr[MAXN],maxsum;
int main()
{
    scanf("%d",&t);
    while(t--&&scanf("%d",&n))
    {
        maxsum=~(0xffffff)+1;
        for(int i=0;i<n&&scanf("%d",&arr[i]);i++);
        for(int i=0,sum=0;i<n;i++)
        {
            sum+=arr[i],maxsum=max(sum,maxsum);
            if(sum<0) sum=0;
        }
        printf("%d\n",maxsum);
    }
    return 0;
}
