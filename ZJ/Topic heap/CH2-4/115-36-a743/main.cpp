#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    map<string,int> Ans;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s;
        string x;
        getline(cin,x);
        if(Ans.find(s)!=Ans.end())
            Ans[s]++;
        else
            Ans[s]=1;
    }
    for(map<string,int>::iterator it=Ans.begin();it!=Ans.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
