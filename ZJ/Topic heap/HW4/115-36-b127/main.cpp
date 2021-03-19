#include <bits/stdc++.h>

using namespace std;

int f(int N)
{
    int F[2]{1,1};
    if(N==0)
        return 1;
    else if(N==1)
        return 1;
    else
    {
        for(int i=2;i<=(N/2+1);i++)
        {
            F[0]=F[0]+F[1];
            //cout<<"F[0]:"<<F[0]<<endl;
            F[1]=F[0]+F[1];
            //cout<<"F[1]:"<<F[1]<<endl;
        }
    }

    return F[N%2];
}

int main()
{
    int n;
    while(cin>>n)
    {
        cout<<f(n)<<endl;
    }
    return 0;
}
