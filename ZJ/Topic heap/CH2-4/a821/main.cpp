#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
map<string,set<string> > Team;
map<string,bool> Team_record;
int main()
{
    string a,b;
    for(int N,R;cin>>N>>R;Team.clear())
    {
        cin.ignore();
        for(int i=0;i<R&&cin>>a>>b;cin.ignore(),i++) Team[a].insert(b),Team_record[b]=true;
        for(auto it=Team.begin();it!=Team.end();it++)
            if(it->second.size()==N-1&&!Team_record[it->first]) {cout<<it->first<<'\n'; break;}
    }
    return 0;
}
/*
3 3
tpa azf
tpa abc
azf abc

5 11
tpa azf
azf abc
tpa abc
abc xyz
tpa abcde
xyz abc
azf abcde
azf xyz
abc azf
tpa xyz
azf abcde
*/
