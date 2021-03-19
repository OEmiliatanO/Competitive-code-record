#include <bits/stdc++.h>

using namespace std;

long int f91(long int N)
{
    if(N>=101)
        return N-10;
    else if(N<=100)
        return f91(f91(N+11));
}

int main()
{
    long int N;
    while(cin>>N)
    {
        if(N==0)
            break;
        cout<<"f91("<<N<<") = "<<f91(N)<<endl;
    }
    return 0;
}
