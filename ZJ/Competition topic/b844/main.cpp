#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,Q;
    while(scanf("%d %d",&N,&Q)==2&&N&&Q)
    {
        vector<int> K(N);
        for(int i=0;i<N;i++)
            scanf("%d",&K[i]);
        sort(K.begin(),K.end());
        for(int i=0,x;i<Q;i++)
        {
            scanf("%d",&x);
            vector<int>::iterator it=upper_bound(K.begin(),K.end(),x);
            printf(((it-K.begin())%2?"1\n":"0\n"));
        }
    }
    return 0;
}
