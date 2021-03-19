#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=10000001;
bool isPrime[MAXN];
int l,r,T,ans;
void swap(int &a,int &b)
{
    int tmp=a;
    a=b;
    b=tmp;
}
int main()
{
    memset(isPrime,true,MAXN);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<MAXN;i++)
        if(isPrime[i])
            for(long long t=(long long)i*i;t<MAXN;t+=i)
                isPrime[t]=false;
    scanf("%d",&T);
    while(T--&&~scanf("%d %d",&l,&r))
    {
        if(l>r) swap(l,r);
        ans=0;
        for(int i=l;i<=r;i++)
            ans+=isPrime[i];
        printf("%d\n",ans);
    }
    return 0;
}
