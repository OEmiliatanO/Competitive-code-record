#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,i=0;
    while(cin>>N)
    {
        if(N<=-1)
            break;
        if(N==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        double Log2_N=log10(N)/log10(2);
        cout<<"Case "<<++i<<": "<<ceil(Log2_N)<<endl;
    }
    return 0;
}
