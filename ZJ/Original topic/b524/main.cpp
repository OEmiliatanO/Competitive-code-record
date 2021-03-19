#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str;
int main()
{
    ios_base::sync_with_stdio(false);
    for(;cin>>str;)
    {
        int length=str.length(),i,t;
        long long sum=0;
        for(i=0,t=0;i<length;i++)
            if(str[i]=='y') {sum+=abs(i-t); t+=3;}
        cout<<sum<<'\n';
    }
    return 0;
}
