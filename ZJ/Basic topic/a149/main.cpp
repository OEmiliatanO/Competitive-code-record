#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string in;
        int Len,ans=1;
        cin>>in;
        Len=in.length();
        for(int _=0;_<Len;_++)
        {
            ans*=(in[_]-'0');
        }
        cout<<ans<<endl;
    }
    return 0;
}
