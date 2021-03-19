#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        for(int i=0,j=n-1;i<=j;)
        {
            for(int _i=i;_i<=j;_i++)
            {
                cout<<arr[_i]<<" ";
            }

            cout<<endl;
            i++;
            for(int _j=j;_j>=i;_j--)
            {
                cout<<arr[_j]<<" ";
            }

            cout<<endl;
            j--;
        }
    }
    return 0;
}
