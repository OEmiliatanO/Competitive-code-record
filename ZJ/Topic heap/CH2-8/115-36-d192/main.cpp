#include <bits/stdc++.h>

using namespace std;

int f(int n,int m)
{
    if(n<1||m<1) return 0;
    int res=0;
    for(int i=2;i<=n;i++)
        res=(res+m)%i;
    return res+1;
}

int main()
{
    int t,T=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        printf("Case %d: %d\n",++T,f(n,k));
    }
    return 0;
}
