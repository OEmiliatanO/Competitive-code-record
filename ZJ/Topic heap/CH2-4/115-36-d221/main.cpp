#include <bits/stdc++.h>

using namespace std;
typedef long long INT64;
int main()
{
    for(int n;scanf("%d",&n)&&n;)
    {
        priority_queue<INT64,vector<INT64>,greater<INT64> > qu;
        INT64 _,ans=0;
        for(int i=0,x;i<n&&scanf("%d",&x);i++)
            qu.push(x);
        while(qu.size()>1)
        {
            _=qu.top(); qu.pop();
            _+=qu.top(); qu.pop();
            qu.push(_);
            ans+=_;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
