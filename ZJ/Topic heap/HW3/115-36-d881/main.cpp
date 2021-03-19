#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int n,a,d,ans;
    while(cin>>n)
    {
        a=1;
        ans=1;
        if(n==0)
        {
            cout<<"50"<<endl;
        }
            for(int j=1,i=1;i<=49;j+=n,i++)
            {
                a+=j;
                //cout<<"a"<<i<<":"<<a<<endl;
                ans+=a;
                //cout<<"ans"<<1<<"~"<<i+1<<":"<<ans<<endl;
            }
        cout<<ans<<endl;
    }
    return 0;
}
