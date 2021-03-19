#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=500001;
int f[MAXN],floorsmax=0;
inline int abs(const int a)
{
    return (a<0?~a+1:a);
}
inline bool cmp(const int &a,const int &b)
{
    return abs(a)<abs(b);
}
int main()
{
    int p,ans=1,now;scanf("%d",&p);
    for(int n;p--&&scanf("%d",&n);floorsmax=0,ans=1)
    {
        for(int i=0,in;i<n&&scanf("%d",&in);i++)
            f[floorsmax++]=in;
        sort(f,f+floorsmax,cmp);
        now=0;
        for(int next=1;next<floorsmax;next++)
        {
            if((f[now]^f[next])<0)
            {
                now=next;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
2
5
7 -2 6 9 -3
8
11 -9 2 5 18 17 -15 4
*/
