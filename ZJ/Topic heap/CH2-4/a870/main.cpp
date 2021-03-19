#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    string common;
    list<string> List;
    int t=0;
    for(string X;cin>>common&&common[0]!='S';)
    {
        cin.ignore();
        if(common[0]=='A')
        {
            cin>>X;
            List.push_back(X);
        }
        else if(common[0]=='I')
        {
            string N;
            cin>>X>>N;
            for(auto it=List.begin();it!=List.end();it++)
                if(*it==N) {List.insert(it,X); break;}
        }
        else if(common[0]=='R')
        {
            cin>>X;
            for(auto it=List.begin();it!=List.end();it++)
                if(*it==X) {List.erase(it); break;}
        }
    }
    for(auto it=List.begin();it!=List.end();it++)
        cout<<*it<<" ";
    return 0;
}
