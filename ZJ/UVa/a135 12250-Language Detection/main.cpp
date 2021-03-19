#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    for(int t=1;getline(cin,s,'\n')&&(s[0]!='#'||s[1]!='\0');t++)
    {
        cout<<"Case "<<t<<": ";
        if(s=="HELLO")
            cout<<"ENGLISH"<<'\n';
        else if(s=="HOLA")
            cout<<"SPANISH"<<'\n';
        else if(s=="HALLO")
            cout<<"GERMAN"<<'\n';
        else if(s=="BONJOUR")
            cout<<"FRENCH"<<'\n';
        else if(s=="CIAO")
            cout<<"ITALIAN"<<'\n';
        else if(s=="ZDRAVSTVUJTE")
            cout<<"RUSSIAN"<<'\n';
        else cout<<"UNKNOWN"<<'\n';
    }
    return 0;
}
