#include <bits/stdc++.h>

using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,ans=0;
        scanf("%d",&n);
        vector<int> p(n);
        for(int i=0,in;i<n&&scanf("%d",&in)==1;i++)
            p[i]=in;
        sort(p.begin(),p.end(),cmp);
        for(int i=2;i<n;i+=3)
            ans+=p[i];
        printf("%d\n",ans);
    }
    return 0;
}
