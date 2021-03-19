#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string s;
    stringstream ss;
    for(int n;getline(cin,s,'\n')&&s[0]!='-';ss.clear(),ss.str(""))
    {
        ss.str(s);
        if(s[1]=='x') {ss>>hex>>n; printf("%d\n",n);}
        else {ss>>dec>>n; printf("0x%X\n",n);}
    }
    return 0;
}
