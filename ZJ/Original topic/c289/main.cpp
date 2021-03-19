#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<string> v(100000);
int n,similar=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(;cin>>n&&n;similar=0)
    {
        for(int i=0;i<n&&cin>>v[i];i++);
        sort(v.begin(),v.begin()+n);
        for(int i=0;i<n-1;i++)
        {
            int _=0,length=min(v[i].length(),v[i+1].length());
            for(int j=0;j<length;j++)
                if(v[i][j]==v[i+1][j]) _++;
                else break;
            similar=(_>similar?_:similar);
        }
        cout<<similar<<'\n';
    }
    return 0;
}
