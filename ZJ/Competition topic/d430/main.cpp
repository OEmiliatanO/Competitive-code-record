#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0),cin.tie(0);
    int cnt=0;
    while(cin>>s)
        for(int i=0;i<s.length();i++)
            if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9'){cnt++; break;}
    cout<<cnt<<'\n';
    return 0;
}
