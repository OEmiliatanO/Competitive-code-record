#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
set<LL> Square;
int num[10];
int N[10];
bool ans=false;
inline bool check(LL n)
{
    while(n!=0)
    {
        if(!N[n%10]) {return false;}
        N[n%10]--;
        n/=10;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    for(LL i=32;i<=1e5;i++)
        Square.insert(i*i);
    for(LL s;cin>>s;ans=false)
    {
        memset(num,0,sizeof(num));
        memset(N,0,sizeof(N));
        LL _=s;
        int len=0;
        while(s!=0)
        {
            num[s%10]++;
            N[s%10]++;
            s/=10;
            len++;
        }
        LL BtLimit=pow(10,len-1),ToLimit=BtLimit*10;
        auto x=Square.lower_bound(BtLimit);
        for(;*x<ToLimit;x++)
        {
            if(check(*x))
            {
                ans=true;
                cout<<*x<<' ';
            }
            memcpy(N,num,sizeof(num));
        }
        if(!ans) cout<<"0";
        cout<<'\n';
    }
    return 0;
}
