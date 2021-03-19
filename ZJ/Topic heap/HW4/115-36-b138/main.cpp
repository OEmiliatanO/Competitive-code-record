#include <bits/stdc++.h>

using namespace std;

int main()
{
    int apple[10];
    int hight;
    while(cin>>apple[0])
    {
        for(int i=1;i<=9;i++)
        {
            cin>>apple[i];
        }
        cin>>hight;

        hight+=30;
        int ans=0;
        for(int i=0;i<10;i++)
        {
            if(hight>=apple[i])
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
