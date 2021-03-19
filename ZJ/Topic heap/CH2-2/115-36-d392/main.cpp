#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        long int a,sum=0;
        stringstream ss;
        ss<<s;
        while(ss>>a)
            sum+=a;
        cout<<sum<<endl;
    }
    return 0;
}
