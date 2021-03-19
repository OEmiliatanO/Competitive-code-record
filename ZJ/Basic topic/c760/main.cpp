#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>s)
    {
        cout<<(char)toupper(s[0]);
        for(int i=1;i<s.length();i++) cout<<s[i];
        cout<<" "<<'\n';
    }
    return 0;
}
