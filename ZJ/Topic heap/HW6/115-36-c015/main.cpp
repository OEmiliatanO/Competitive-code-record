#include <bits/stdc++.h>

using namespace std;

int _count=0;

int ToReverse(int N)
{
    int n=N;
    int Reverse_Of_N=0;
    int Count=0;
    while(n!=0)
    {
        n/=10;
        Count++;
    }
    n=N;
    int i=0;
    while(Count--)
    {
        int x=(n/pow(10.0,Count));
        Reverse_Of_N+=(x*pow(10.0,i));
        i++;
        //cout<<"x="<<x<<endl;
        //cout<<"Reverse="<<Reverse_Of_N<<endl;
        n%=(int)ceil(pow(10,Count));
        //cout<<"n="<<n<<endl;
        //system("pause");
    }
    //cout<<Reverse_Of_N<<endl;
    //system("pause");
    if(N!=Reverse_Of_N||_count==0)
    {
        _count++;
        return ToReverse(N+Reverse_Of_N);
    }
    else if(N==Reverse_Of_N)
    {
        return N;
    }
}

int main()
{
    int N;
    cin>>N;
    int num;
    while(N--)
    {
        cin>>num;
        cout<<_count<<" "<<ToReverse(num)<<endl;
        _count=0;
    }
    return 0;
}
