#include <iostream>
#include <string>
#define max(x,y) (x)>(y)?(x):(y)
using namespace std;
typedef struct _site
{
    string name;
    int V;
}site;
site Web[10];
int T;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    cin.ignore();
    for(int t=1,maxx=-1;t<=T;maxx=-1,t++)
    {
        for(int i=0;i<10;cin.ignore(),maxx=max(maxx,Web[i].V),i++)
            cin>>Web[i].name>>Web[i].V;
        cout<<"Case #"<<t<<":"<<'\n';
        for(int i=0;i<10;i++)
            if(maxx==Web[i].V) cout<<Web[i].name<<'\n';
    }
    return 0;
}
