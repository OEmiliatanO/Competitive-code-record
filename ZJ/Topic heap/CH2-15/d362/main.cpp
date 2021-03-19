#include <cstring>
#include <cstdio>
using namespace std;
using uint64=unsigned long long;
using uint=unsigned int;
const int MAXN=20000001;
bool isprime[MAXN];
int prime[1271000],cnt=0;
int twin_prime[1271000],t_cnt=0;
int main()
{
    memset(isprime,true,MAXN);
    for(uint i=2;i<20000000;i++)
    {
        if(isprime[i]) prime[cnt++]=i;
        for(uint64 j=0;j<cnt&&i*prime[j]<MAXN;j++)
        {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
    for(int i=0;i<cnt;i++)
        if(prime[i]+2==prime[i+1]) twin_prime[t_cnt++]=prime[i];
    for(int S;scanf("%d",&S)!=EOF;printf("(%d, %d)\n",twin_prime[S-1],twin_prime[S-1]+2));
    return 0;
}
