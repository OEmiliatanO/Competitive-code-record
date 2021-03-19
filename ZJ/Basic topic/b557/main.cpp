#include <cstdio>
using namespace std;
int a[101],T,N,ans;
int main()
{
    scanf("%d",&T);
    while(T--&&scanf("%d",&N))
    {
        ans=0;
        for(int i=0;i<N&&scanf("%d",&a[i]);i++);
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                for(int k=0;k<N;k++)
                    ans+=(a[i]*a[i]+a[j]*a[j]==a[k]*a[k]);
        printf("%d\n",ans/2);
    }
    return 0;
}
