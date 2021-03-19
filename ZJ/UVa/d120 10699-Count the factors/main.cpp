#include <cstdio>
#include <cmath>
using namespace std;
int Prime[90000],p=2;
void IsPrime(int n)
{
    int SQ=ceil(sqrt(n));
    for(int i=0;i<p&&Prime[i]<=SQ;i++)
        if(n%Prime[i]==0) return;
    Prime[p++]=n;
}
int main()
{
    Prime[0]=2;
    Prime[1]=3;
    for(int i=5;p<=89999;i++)
        IsPrime(i);
    for(int n,_n,cnt=0;scanf("%d",&n)!=EOF&&n>0;cnt=0)
    {
        _n=n;
        for(int i=0;Prime[i]<=n&&i<p;i++)
            if(n%Prime[i]==0)
            {
                cnt++;
                n/=Prime[i];
                while(n%Prime[i]==0) n/=Prime[i];
            }
        printf("%d : %d\n",_n,cnt);
    }
    return 0;
}
