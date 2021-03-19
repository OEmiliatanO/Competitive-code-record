#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int arr[n];
        int d[n-1];
        for(int i=1;i<=n;i++)
            cin>>arr[i-1];

        for(int i=0;i<n-1;i++)
            d[i]=abs(arr[i]-arr[i+1]);
        sort(d,d+n-1);
        if(d[n-2]-d[0]!=n-2)
        {
            cout<<"Not jolly"<<endl;
        }
        else
        {
            cout<<"Jolly"<<endl;
        }
        /*for(int i=0;i<n-1;i++)
            cout<<d[i];*/
    }
    return 0;
}
