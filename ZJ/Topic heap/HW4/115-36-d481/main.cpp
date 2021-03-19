#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        if(b!=c)
        {
            cout<<"Error"<<endl;
            continue;
        }
        long int A[a+1][b+1],B[c+1][d+1],C[a+1][d+1];
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                cin>>A[i][j];
            }
        }
        for(int i=1;i<=c;i++)
        {
            for(int j=1;j<=d;j++)
            {
                cin>>B[i][j];
            }
        }
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=d;j++)
            {
                long int sum=0;
                for(int r=1;r<=b;r++)
                {
                    //cout<<"sum+=A[i][r]*B[r][j]="<<sum+A[i][r]*B[r][j]<<"\ni "<<i<<" r "<<r<<" j "<<j<<endl;
                    sum+=A[i][r]*B[r][j];
                }
                C[i][j]=sum;
                sum=0;
            }
        }
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=d;j++)
            {
                cout<<C[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
