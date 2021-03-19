#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL> point;
bool solve(int r,int N,int K)
{
    int cnt=0;
    vector<LL>::iterator it;
    for(it=point.begin();it!=point.end();)
    {
        int Range=*it+r;
        cnt++;
        if(cnt>K)
            return false;
        if(Range>=point[N-1]&&cnt<=K)
            return true;
        it=upper_bound(point.begin(),point.end(),Range);
    }
    return false;
}
int main()
{
    for(int N,K,result;scanf("%d %d",&N,&K)!=EOF&&N&&K;)
    {
        point.resize(N);
        for(int i=0;i<N&&scanf("%d",&point[i++]););
        sort(point.begin(),point.end());

        int R=point[N-1]-point[0],L=1;
        if(K==1) {printf("%d\n",R); continue;}
        else
            while(L<R)
            {
                int M=(R+L)/2;
                if(solve(M,N,K))
                    R=M;
                else
                    L=M+1;
            }
        printf("%d\n",R);
    }
    return 0;
}
