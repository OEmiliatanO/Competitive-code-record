#include <bits/stdc++.h>

using namespace std;


int main()
{
    int m,n;
    while(cin>>n>>m)
    {
        int ans=1;
        for(int i=m+1;i<=n;i++)
        {
            ans*=i;
            /*cout<<"i="<<i<<endl;
            cout<<"ans="<<ans<<endl;*/
        }
        for(int i=2;i<=n-m;i++)
        {
            ans/=i;
            /*cout<<"i="<<i<<endl;
            cout<<"ans="<<ans<<endl;*/
        }
        cout<<ans<<endl;
    }
    return 0;
}
