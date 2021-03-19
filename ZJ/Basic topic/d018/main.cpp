#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    stringstream ss;
    double Odd=0,Even=0,temp;
    int SerialN;
    char ch;
    for(string s;getline(cin,s,'\n');ss.clear(),ss.str(""),Even=Odd=0)
    {
        ss<<s;
        while(ss>>SerialN)
        {
            ss>>ch;
            ss>>temp;
            if(SerialN%2==0) Even+=temp;
            else Odd+=temp;
        }
        cout<<(Odd-Even)<<'\n';
    }
    return 0;
}
