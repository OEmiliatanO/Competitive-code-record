#include <bits/stdc++.h>

using namespace std;

int main()
{
    int M,f,n;

    cin>>n;
    while(n--)
    {
        cin>>M;
        cin>>f;
        for(int i=1;i<=f;i++)
        {
            for(int j=1;j<=M;j++)
            {
                for(int _=1;_<=j;_++)
                {
                    cout<<j;
                }
                cout<<endl;
            }
            for(int j=M-1;j>=1;j--)
            {
                for(int _=j;_>=1;_--)
                {
                    cout<<j;
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }
    return 0;
}
