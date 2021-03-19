#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
string s;
void com(string &a,string &b,string oper)
{
    for(int i=0;i<a.length();i++)
        if(oper=="and")
            a[i]=(int)((a[i]-'0')&(b[i]-'0'))+'0';
        else
            a[i]=(a[i]-'0')|(b[i]-'0')+'0';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(getline(cin,s))
    {
        stringstream ss(s);
        string a,b,oper;
        ss>>a;
        cout<<a;
        while(ss>>oper)
        {
            if(oper=="and")
                cout<<"&&";
            else
                cout<<"||";
            ss>>b;
            cout<<b;
            com(a,b,oper);
        }
        cout<<" = "<<a<<"\n";
    }
    return 0;
}
