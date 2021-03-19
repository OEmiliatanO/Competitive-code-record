#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int i=0;
    while(cin>>s)
    {
        i=s.length()-1;
        if(s[0]=='-') cout<<"-";
        while(s[i]=='0'&&i>=0) i--;
        for(;i>=0;i--) if(s[i]>='0'&&s[i]<='9')cout<<s[i];
    }
    return 0;
}
