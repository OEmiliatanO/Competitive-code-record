#include <iostream>
using namespace std;
int knight[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    for(int n,qu;cin>>n&&n;)
    {
        for(int i=1,p;i<=n&&cin>>i>>p;i++)
            for(int j=0,in;j<p&&cin>>in;knight[in]=i,j++);
        cin>>qu;
        cout<<knight[qu]<<'\n';
    }
    return 0;
}
