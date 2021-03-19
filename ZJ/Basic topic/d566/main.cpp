#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
map<string,bool> Table;
set<string> AC_people;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,killer=0,AC=0;
    cin>>n;
    for(string name,status;n--&&cin>>name>>status;)
    {
        cin.ignore();
        if(status[0]=='A') AC_people.insert(name);
        Table[name]=(status[0]=='A'?true:false);
    }
    for(auto it:Table)
        if(it.second) killer++;
    cout<<killer*100/AC_people.size()<<'%'<<'\n';
    return 0;
}
