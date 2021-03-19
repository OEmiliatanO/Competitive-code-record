#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(int n,k;scanf("%d %d",&n,&k)==2&&n;)
    {
        vector<int> v(n);
        vector<int>::iterator it;
        for(int i=0,in;i<n&&scanf("%d",&in);i++)
            v[i]=in;
        for(int i=0,in;i<k&&scanf("%d",&in);i++)
        {
            it=lower_bound(v.begin(),v.end(),in);
            if(*it==in) printf("%d\n",(it-v.begin())+1);
            else printf("0\n");
        }
    }
    return 0;
}
