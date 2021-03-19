#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int n,m;
bool Path[30],ans;

void go(int i,int sum)
{
    if(sum==m)
    {
        ans=true;
        for(int i=0;i<n;i++)
        {if(Path[i]==true){printf("%d ",v[i]);}}

        printf("\n");
        return;
    }
    if(i==n||sum>m) return;
    for(int _i=i;_i<n;_i++)
    {
        Path[_i]=true;
        go(_i+1,sum+v[_i]);
        Path[_i]=false;
    }
}

int main()
{
    for(;scanf("%d %d",&n,&m)!=EOF&&n;)
    {
        v.resize(n);
        memset(Path,0,sizeof(Path));
        ans=false;

        for(int i=0;i<n&&scanf("%d",&v[i]);i++);
        sort(v.begin(),v.end());
        go(0,0);
        if(!ans) printf("-1\n");
    }
    return 0;
}
