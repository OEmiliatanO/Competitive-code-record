#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
        {
            cout<<endl;
            continue;
        }

        int TheFirst=1+(n-1)*2;
        for(int i=1;i<=n;i++)
        {
            for(int j=TheFirst/2-i+1;j>=1;j--)
            {
                cout<<"_";
            }
            for(int _=1;_<=1+(i-1)*2;_++)
            {
                cout<<"*";
            }
            for(int j=TheFirst/2-i+1;j>=1;j--)
            {
                cout<<"_";
            }
            cout<<endl;
        }

    }
    return 0;
}
