#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while(scanf("%d",&N)==1&&N)
    {
        vector<int> v;
        for(int i=0;i<N;i++)
        {
            int X;
            scanf("%d",&X);
            v.push_back(X);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<N;i++)
        {
            printf("%d",v[i]);
            if(i!=N-1)
                printf(" ");
        }
    }
    return 0;
}
