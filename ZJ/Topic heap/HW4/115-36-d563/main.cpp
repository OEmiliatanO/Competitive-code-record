#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int arr[n];
        int ans=0;
        int dif=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        dif+=arr[0];
        dif-=arr[n-1];

        //cout<<"dif "<<dif<<endl;

        for(int i=1,j=n-2;i<n&&j>=0;)
        {
            if(dif<0)
            {
                dif+=arr[i++];
                if(dif==0)
                {
                    ans++;
                    dif-=arr[j--];
                }
            }
            else if(dif>0)
            {
                dif-=arr[j--];
                if(dif==0)
                {
                    ans++;
                    dif+=arr[i++];
                }
            }

        }
        cout<<++ans<<endl;
    }
    return 0;
}
