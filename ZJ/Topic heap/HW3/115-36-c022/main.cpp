#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int N=n;
    int a,b,ans=0;
    while(n--)
    {
        cin>>a;
        cin>>b;
        for(int _=a;_<=b;_++)
        {
            if(_%2==1)
            {
                ans+=_;
            }
        }
        printf("Case %d: %d\n",N-n,ans);
        ans=0;
    }
    return 0;
}
