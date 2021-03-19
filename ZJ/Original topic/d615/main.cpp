#include <string>
#include <iostream>
using namespace std;
typedef long long int64;
string s;
int64 strToint(string &s,int &i)
{
    while(s[i]<'0'||s[i]>'9') i++;
    if(i>=s.length()) return 0;
    int64 re=0;
    while(i<s.length()&&s[i]>='0'&&s[i]<='9')
        re=(re*10+s[i++]-'0');
    return re;
}
int main()
{
    int64 a,b;
    char sy;
    int T,i;cin>>T;cin.ignore();
    while(T--&&getline(cin,s,'\n'))
    {
        i=0;
        a=strToint(s,i);
        sy=s[++i];
        for(;i<s.length();)
        {
            b=strToint(s,i);
            if(sy=='+')
                a+=b;
            else if(sy=='-')
                a-=b;
            else if(sy=='*')
                a*=b;
            else if(sy=='/')
                a/=b;
            sy=s[++i];
        }
        cout<<a<<'\n';
    }
    return 0;
}
