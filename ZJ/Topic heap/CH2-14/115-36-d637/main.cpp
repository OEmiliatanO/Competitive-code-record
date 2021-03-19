#include <cstdio>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
int n;
int tot[101]={0},v[10001],eat[10001];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n&&scanf("%d %d",&v[i],&eat[i]);i++);
    for(int i=1;i<=n;i++)
        for(int j=100;j>=v[i];j--)
            tot[j]=max(tot[j-v[i]]+eat[i],tot[j]);
    printf("%d",tot[100]);
    return 0;
}
