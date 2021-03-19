#include <cmath>
#include <cstdio>

using namespace std;
int prime[5000];
bool isPrime(int n,int p)
{
    for(int i=0;i<p;i++)
        if(n!=prime[i]&&!(n%prime[i]))return false;
    return true;
}
int main()
{
    prime[0]=2;
    prime[1]=3;
    int top=(int)ceil(sqrt(2147483647)),p=2;
    for(int i=4;i<=top;i++)
        if(isPrime(i,p)) prime[p++]=i;

    for(int n;scanf("%d",&n)!=EOF;)
        printf((isPrime(n,p)?"質數\n":"非質數\n"));
    return 0;
}
