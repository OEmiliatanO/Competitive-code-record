#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        bool Finish=false;
        int arr[n];
        int _count=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        while(!Finish)
        {
            Finish=true;
            for(int i=0;i+1<n;i++)
            {
                if(arr[i]>arr[i+1])
                {
                    Finish=false;
                    _count++;
                    int t= arr[i+1];
                    arr[i+1]=arr[i];
                    arr[i]=t;
                }
            }
        }
        cout<<_count<<endl;
    }
    return 0;
}
