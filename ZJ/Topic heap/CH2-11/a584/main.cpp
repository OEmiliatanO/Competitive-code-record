#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,string> m;
int main()
{
    string a,b,fa_node,son_node,a_group[50],b_group[50];
    int n,len,tmp1,tmp2;
    cin>>n;cin.ignore();
    while(n--)
    {
        getline(cin,a,'\n');
        len=a.length();
        fa_node=a.substr(0,3);
        for(int i=4;i<len;i+=4) m[a.substr(i,3)]=fa_node;
    }
    cin>>a>>b;
    for(tmp1=0;!a.empty();a=m[a],tmp1++)
        a_group[tmp1]=a;
    for(tmp2=0;!b.empty();b=m[b],tmp2++)
        b_group[tmp2]=b;
    while(a_group[tmp1-1]==b_group[tmp2-1]&&tmp1>=1&&tmp2>=1)
        tmp1--,tmp2--;
    cout<<tmp1+tmp2<<'\n';
    return 0;
}
