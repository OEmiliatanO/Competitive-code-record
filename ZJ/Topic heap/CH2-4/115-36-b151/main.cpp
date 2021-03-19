#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ans=0;
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int> > qu;
    while(n--)
    {
        int x;
        scanf("%d",&x);
        qu.push(x);
    }
    while(qu.size()>1)
    {
        int x=qu.top(); qu.pop();
        x+=qu.top(); qu.pop();
        qu.push(x);
        ans+=x;
    }
    printf("%d\n",ans);
    return 0;
}
