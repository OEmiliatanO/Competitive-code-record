#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int arr[n+1]={0};
        int A=0;
        int MAX=0;

        cin>>arr[0];
        A=arr[0];

        for(int i=1;i<n;i++)
        {
            cin>>arr[i];
            if(A<arr[i])
            {
                A=arr[i];
            }
            else if(MAX<A-arr[i])
            {
                MAX=A-arr[i];
            }
        }
        cout<<MAX<<endl;
    }
    return 0;
}
