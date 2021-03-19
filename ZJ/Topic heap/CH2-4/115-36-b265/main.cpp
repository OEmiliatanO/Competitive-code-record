#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(int n;scanf("%d",&n)&&n;)
    {
        int cls[5];
        map<string,int> M;
        char buf[20];
        for(int _=0;_<n;_++)
        {
            scanf("%d %d %d %d %d",&cls[0],&cls[1],&cls[2],&cls[3],&cls[4]);
            sort(cls,cls+5);
            string s;
            sprintf(buf,"%d%d%d%d%d",cls[0],cls[1],cls[2],cls[3],cls[4]);
            s=buf;
            M[s]++;
        }
        int ans=0,Max=0;
        for(map<string,int>::iterator it=M.begin();it!=M.end();it++)
        {
            if((it->second)>Max)
                Max=it->second, ans=0;
            if((it->second)==Max)
                ans+=Max;
        }
        printf("%d\n",ans);
    }
    return 0;
}
