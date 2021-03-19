#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
int Prime[170],p=2;
bool Number[1001];
inline void isPrime(int N)
{
    for(int i=0;Prime[i]<N&&i<p;i++)
        if(N%Prime[i]==0)
            return;
    Prime[p++]=N;
}
int main()
{
    Prime[0]=2,Prime[1]=3;
    for(int i=5;i<998;i+=2)
        isPrime(i);
    for(int S,T,now,next,kase=1,t=-1;scanf("%d %d",&S,&T)&&(S||T);t=-1,kase++)
    {
        memset(Number,false,sizeof(Number));
        queue<pair<int,int> > qu;
        qu.push(make_pair(S,0)),Number[S]=true;
        while(!qu.empty())
        {
            now=qu.front().first;
            if(now==T){t=qu.front().second; break;}
            for(int i=0;now>Prime[i]&&i<p;i++)
            {
                next=now+Prime[i];
                if(next<=T&&!Number[next]&&now%Prime[i]==0)
                    qu.push(make_pair(next,qu.front().second+1)),Number[next]=true;
                else if(next>T)
                    break;
            }
            qu.pop();
        }
        printf("Case %d: %d\n",kase,t);
    }
    return 0;
}
