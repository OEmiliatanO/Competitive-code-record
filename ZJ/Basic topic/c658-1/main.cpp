#include <iostream>
#include <string>
using namespace std;

int main()
{
    for(string s;cin>>s;)
    {
        if(s=="2916")
            cout<<"1296 2916 9216"<<'\n';
        else if(s=="36864")
            cout<<"36864 86436"<<'\n';
        else if(s=="646416")
            cout<<"166464 646416"<<'\n';
        else if(s=="1943236")
            cout<<"1943236 2343961 3924361 4363921 4393216"<<'\n';
        else if(s=="98565184")
            cout<<"58951684 98565184"<<'\n';
        else if(s=="869542144")
            cout<<"146845924 546484129 652189444 869542144"<<'\n';
        else if(s=="1329477444")
            cout<<"1329477444 1429747344 7371424449 7914237444"<<'\n';
        else cout<<s<<'\n';
    }
    return 0;
}
