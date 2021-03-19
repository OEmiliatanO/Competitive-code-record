#include <cstdio>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
int val[26],w[26],tot[30001],N,m;
int main()
{
    scanf("%d %d",&N,&m);
    for(int i=1;i<=m&&scanf("%d %d",&w[i],&val[i]);val[i]*=w[i],i++);
    for(int i=1;i<=m;i++)
        for(int j=N;j>=w[i];j--)
            tot[j]=max(tot[j],tot[j-w[i]]+val[i]);
    printf("%d",tot[N]);
    return 0;
}
