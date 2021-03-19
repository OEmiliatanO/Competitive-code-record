#include <bits/stdc++.h>

using namespace std;

bool IsSqrt(int n)
{
    int _=sqrt(n);
    if(_*_!=n)
        return false;
    return true;
}

int main()
{
    int T,ca=0;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,ans=0;
        scanf("%d %d",&a,&b);
        for(int i=a;i<=b;i++)
        {
            if(IsSqrt(i))
                ans+=i;
        }
        printf("Case %d: %d\n",++ca,ans);
    }
    return 0;
}
