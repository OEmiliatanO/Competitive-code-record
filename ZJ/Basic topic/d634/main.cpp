#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<string> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int n;cin>>n&&n;)
    {
        cin.ignore();
        v.resize(n);
        for(int i=0;i<n;getline(cin,v[i],'\n'),i++);
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++) cout<<v[i]<<'\n';
    }
    return 0;
}
