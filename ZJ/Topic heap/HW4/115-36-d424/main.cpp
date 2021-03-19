#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h,l,r,build[10001]={0};
    while(cin>>l>>h>>r)
    {
        for(int i=l;i<r;i++)
        {
            if(h>build[i])
                build[i]=h;
        }
    }

    for(int i=0;i<10001;i++)
    {
        if(build[0]&&i==0)
            cout<<"0 "<<build[0]<<" ";
        if(build[i+1]!=build[i])
        {
            cout<<i+1<<" "<<build[i+1]<<" ";
        }
    }
    cout<<endl;
    return 0;
}
