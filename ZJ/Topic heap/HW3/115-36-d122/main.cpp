#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int n;
    while(cin>>n)
    {
        int i=0;
        while(n>=5)
        {
            i+=n/5;
            n/=5;
        }
        cout<<i<<endl;
    }

    return 0;
}
