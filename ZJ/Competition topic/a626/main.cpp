#include <cstdio>
using namespace std;
int prime[200]{2,3,5,7};
int p=4,n;
bool isPrime(int n)
{
    for(int i=0;i<p;i++)
        if(n%prime[i]==0) return false;
    return true;
}
int main()
{
    for(int i=11;i<=1000;i++)
    {
        if(isPrime(i)) prime[p++]=i;
    }
    while(~scanf("%d",&n))
    {
        int t=0,_p=0;
        while(prime[_p]<=n&&_p<p)
        {
            if(t==5) {t=0; putchar('\n');}
            printf("%10d",prime[_p++]);
            t++;
        }
        putchar('\n');
    }
    return 0;
}
