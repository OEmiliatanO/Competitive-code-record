#include <iostream>
using namespace std;
int len;
void dfs(int n,string s)
{
    if(n>len)
        cout<<s<<'\n';
    else
    {
        dfs(n+1,s+'0');
        dfs(n+1,s+'1');
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0),cin.tie(0);
    while(cin>>len)
        dfs(1,"");
    return 0;
}
