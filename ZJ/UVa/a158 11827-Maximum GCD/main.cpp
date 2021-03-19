#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int M[101];
int main()
{
    int T,Maxgcd=-1,p=0;
    cin>>T;
    cin.ignore();
    stringstream ss;
    for(string s;T--&&getline(cin,s,'\n')&&!s.empty();p=0,Maxgcd=-1)
    {
        ss<<s;
        while(ss>>M[p++]);
        p--;
        for(int i=0;i<p;i++)
            for(int j=0;j<p;j++)
            {
                if(i==j) continue;
                int GCD=__gcd(M[i],M[j]);
                Maxgcd=max(GCD,Maxgcd);
            }
        ss.clear();
        ss.str("");
        cout<<Maxgcd<<'\n';
    }
    return 0;
}
