#include <cstdio>
#include <cstring>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
int tot[10001],wi[101],v[101],n,lim;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(tot,0,sizeof(tot));
        for(int i=1;i<=n&&scanf("%d %d",&wi[i],&v[i]);i++);
        scanf("%d",&lim);
        for(int i=1;i<=n;i++)
            for(int j=lim;j>=wi[i];j--)
                tot[j]=max(tot[j-wi[i]]+v[i],tot[j]);
        printf("%d\n",tot[lim]);
    }
    return 0;
}
