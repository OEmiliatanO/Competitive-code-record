#include <bits/stdc++.h>

using namespace std;

int R=0,C=0,M,NowR,NowC;

void Filp(int *a)
{
    int b[R*C]={0};
    int Bi=0;
    for(int i=R*C-NowC;i>=0;i-=NowC)
    {
        for(int j=0;j<NowC;j++)
        {
            b[Bi]=a[i+j];
            Bi++;
        }
    }
    /*cout<<"Filp"<<endl;
    for(int i=0;i<R*C;i++)
    {
        if(i%NowC==0)
            cout<<endl;
        cout<<b[i]<<" ";
    }
    cout<<endl;*/
    for(int i=0;i<R*C;i++)
        a[i]=b[i];
}

void Rotae(int *a)
{
    int b[R*C];
    int Bi=0;
    for(int i=NowC-1;i>=0;i--)
    {
        for(int j=i;j<C*R;j+=NowC)
        {
            b[Bi]=a[j];
            Bi++;
        }
    }
    for(int i=0;i<R*C;i++)
        a[i]=b[i];

    int T=NowR;
    NowR=NowC;
    NowC=T;
    /*cout<<"Rotae"<<endl;
    for(int i=0;i<R*C;i++)
    {
        if(i%NowC==0)
            cout<<endl;
        cout<<b[i]<<" ";
    }
    cout<<"\n========"<<endl;*/
}


int main()
{
    while(cin>>R>>C>>M)
    {
        NowR=R;
        NowC=C;
        int A[R*C];
        int m[M];
        for(int i=0;i<R*C;i++)
        {
            cin>>A[i];
        }
        for(int i=0;i<M;i++)
        {
            cin>>m[i];
        }
        for(int i=M-1;i>=0;i--)
        {
            if(m[i]==1)
                Filp(A);
            else if(m[i]==0)
                Rotae(A);
        }
        cout<<NowR<<" "<<NowC;
        for(int i=0;i<R*C;i++)
        {
            if(i%NowC==0)
                cout<<endl;
            if((i+1)%NowC==0&&i<R*C)
                cout<<A[i];
            else
                cout<<A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

