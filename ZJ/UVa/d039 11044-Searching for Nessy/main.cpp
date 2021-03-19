#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,ans;
        scanf("%d%d",&n,&m);
        ans=floor(n/3.0)*floor(m/3.0);
        printf("%d\n",ans);
    }
    return 0;
}
