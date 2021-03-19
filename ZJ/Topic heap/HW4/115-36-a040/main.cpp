#include <bits/stdc++.h>

using namespace std;

bool IsArmNum(int N)
{
    int Sum[101];
    int _sum=0;
    int n=N;
    memset(Sum,0,sizeof(Sum));
    int p=0;

    while(N!=0)
    {
        p++;
        Sum[p]=N%10;
        N/=10;
    }

    for(int i=1;i<=p;i++)
    {
        _sum=_sum+pow(Sum[i],p);
    }

    if(_sum==n)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        bool B=true;
        for(int i=n;i<=m;i++)
        {
            if(IsArmNum(i))
            {
                cout<<i<<" ";
                B=false;
            }
        }
        if(B)
            cout<<"none";
        cout<<endl;
    }
    return 0;
}
