#include <cstdio>
#include <cstring>
using namespace std;
bool Prime[1001];
int Primes[1001],p;
int N,C,K,l,r;
int main()
{
    memset(Prime,true,sizeof(Prime));
    for(int i=2;i<=1000;i++)
    {
        for(int j=i+i;j<=1000;j+=i)
            Prime[j]=false;
    }
    while(~scanf("%d %d",&N,&C))
    {
        K=p=0;
        for(int i=1;i<=N;i++)
        {
            K+=Prime[i];
            if(Prime[i]) Primes[p++]=i;
        }
        l=p/2-((K&1?C*2-1:C*2)-1)/2;
        if(!(K&1)) l--;
        r=p/2+((K&1?C*2-1:C*2)-1)/2;
        if(l<0) l=0;
        if(r>=p) r=p-1;
        printf("%d %d:",N,C);
        for(int i=l;i<=r;i++)
            printf(" %d",Primes[i]);
        puts("");
    }
    return 0;
}
