#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int _count=1;
    while(cin>>n)
    {
        if(n<=0)
            continue;

        bool IsB2=true;
        int arr[n];
        int num[20010];

        memset(num,0,sizeof(num));

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        for(int i=0;i<n&&IsB2;i++)
        {
            for(int j=i;j<n;j++)
            {
                num[arr[i]+arr[j]]++;
                if(num[arr[i]+arr[j]]>1)
                {
                    IsB2=false;
                    cout<<"Case #"<<_count++<<": It is not a B2-Sequence.\n\n";
                    break;
                }
            }
        }

        if(IsB2)
            cout<<"Case #"<<_count++<<": It is a B2-Sequence.\n\n";
    }
    return 0;
}
