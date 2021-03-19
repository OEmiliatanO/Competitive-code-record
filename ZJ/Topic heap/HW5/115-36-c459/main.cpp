#include <bits/stdc++.h>

using namespace std;

long int ToTen(int b,long int N)
{
    int result=0;
    int powCount=0;
    while(N!=0)
    {
        result+=(N%10)*ceil(pow(b,powCount));
        N/=10;
        powCount++;
    }
    return result;
}
bool isNN(long int N,int n_Ten)
{
    long int n=N;
    int sum=0;
    int d=0;
    while(n!=0)
    {
        d++;
        n/=10;
    }
    //cout<<"d="<<d<<endl;
    while(N!=0)
    {
        sum+=ceil(pow(N%10,d));
        N/=10;
    }
    //cout<<"sum="<<sum<<endl;
    //cout<<"n_Ten"<<n_Ten<<endl;
    if(sum==n_Ten)
        return true;
    else
        return false;
}


int main()
{
    long int N;
    int b;
    while(cin>>b>>N)
    {
        long int n_Ten;
        if(b!=10)
            n_Ten=ToTen(b,N);
        else
            n_Ten=N;
        cout<<(isNN(N,n_Ten)?"YES":"NO")<<endl;
    }
    return 0;
}
