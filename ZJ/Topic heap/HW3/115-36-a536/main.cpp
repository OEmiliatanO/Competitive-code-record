#include <bits/stdc++.h>

using namespace std;

int main()
{
    int e,f,c,n,ans;
    cin>>n;
    while(n--)
    {
        ans=0;
        cin>>e>>f>>c;
        f=e+f;
        while(f>=c)
        {
            ans+=(f/c);
            f=f/c+f%c;
        }
        cout<<ans<<endl;
    }
    return 0;
}
