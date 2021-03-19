#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
bool cmp(string a,string b)
{
    int al=a.length(),bl=b.length();
    if(a[0]=='-')
        if(b[0]=='-')
        {
            if(al!=bl) return al>bl;
            for(int i=1;i<al;i++)
                if(a[i]!=b[i]) return a[i]>b[i];
        }
        else
            return true;
    else
        if(b[0]=='-')
            return false;
        else
        {
            if(al!=bl) return al<bl;
            for(int i=0;i<al;i++)
                if(a[i]!=b[i]) return a[i]<b[i];
        }
    return false;
}
int main()
{
    for(int n;cin>>n&&n>0;)
    {
        cin.ignore();
        v.resize(n);
        for(int i=0;i<n&&getline(cin,v[i],'\n');i++);
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<n;i++) cout<<v[i]<<'\n';
    }
    return 0;
}
