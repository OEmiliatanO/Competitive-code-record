#include <bits/stdc++.h>

using namespace std;

bool cmp(pair <int,int> a,pair <int,int> b)
{
    if(a.second!=b.second)return a.second<b.second;
    else return a.first>b.first;
}

int main()
{
    string s;
    while(getline(cin,s)&&!s.empty())
    {
        pair <int,int> _[127];
        int L=s.length();
        for(int i=0;i<L;i++)
        {
            _[s[i]]=make_pair((int)s[i],++(_[s[i]].second));
        }
        sort(_,_+127,cmp);
        for(int i=0;i<127;i++)
            if(_[i].second!=0) printf("%d %d\n",_[i].first,_[i].second);
    }
    return 0;
}
