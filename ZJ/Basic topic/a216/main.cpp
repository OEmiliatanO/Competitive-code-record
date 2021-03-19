#include <bits/stdc++.h>

using namespace std;
long long f;
long long g;
void all(int n)
{
    f=1,g=1;
    if(n==1) return;
    for(int i=2;i<=n;i++)
    {
        f+=i;
        g+=f;
    }
}

int main()
{
    for(int n;scanf("%d",&n)!=EOF&&n;)
    {
        all(n);
        printf("%lld %lld\n",f,g);
    }
    return 0;
}
