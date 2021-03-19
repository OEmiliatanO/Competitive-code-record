#include <bits/stdc++.h>

using namespace std;

bool cmp(string a,string b)
{
    return (a+b)>(b+a);
}

int main()
{
    for(int N;scanf("%d",&N)!=EOF&&N;)
    {
        vector<string> v(N);
        for(int i=0;i<N&&cin>>v[i];i++);
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<N;i++)
            cout<<v[i];
        cout<<endl;
    }
    return 0;
}
