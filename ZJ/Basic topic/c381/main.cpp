#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int n,m;cin>>n>>m&&n&&m;)
    {
        string s="",result="";
        for(int i=0;i<n;i++)
        {
            string _;
            cin>>_;
            s+=_;
        }
        for(int i=0,in;i<m&&cin>>in&&in;i++)
            result+=s[in-1];
        cout<<result<<"\n";
    }
    return 0;
}
