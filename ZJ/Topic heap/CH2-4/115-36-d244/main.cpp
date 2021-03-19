#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int,int> m;
    for(int n;cin>>n;)
    {
        if(m.find(n)!=m.end()) {m[n]++;}
        else {m[n]=1;}
    }
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        if(it->second==2)
            printf("%d",it->first);
        break;
    }
    return 0;
}
