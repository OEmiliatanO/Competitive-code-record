#include <iomanip>
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,int> Wood;
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int N;
    string s;
    cin>>N;
    cin.ignore();
    cin.ignore();
    for(int cnt=0;N--;cnt=0,Wood.clear())
    {
        while(getline(cin,s,'\n')&&!s.empty())
            Wood[s]++,cnt++;
        for(auto it=Wood.begin();it!=Wood.end();it++)
            cout<<it->first<<" "<<fixed<<setprecision(4)<<(double)it->second/cnt*100<<'\n';
    }
    return 0;
}
