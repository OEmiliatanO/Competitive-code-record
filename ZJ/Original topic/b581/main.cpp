#include <iostream>
#include <string>
#include <sstream>
using namespace std;
typedef long long int64;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    string s;
    stringstream ss;
    cin>>T;
    cin.ignore();
    for(int64 a,sum=0;T--&&getline(cin,s)&&!s.empty();ss.clear(),ss.str(""),sum=0)
    {
        ss<<s;
        while(ss>>a)
            sum+=a;
        cout<<sum<<'\n';
    }
    return 0;
}
