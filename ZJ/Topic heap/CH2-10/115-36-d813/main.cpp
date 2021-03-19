#include <cstdio>
#include <string.h>
using namespace std;
int relation[50010];
int _find(int _p)
{
    if(relation[_p]==_p) return _p;
    else return relation[_p]=_find(relation[_p]);
}
int main()
{
    for(int n,m,t=1,cnt=0;scanf("%d %d",&n,&m)!=EOF&&(n||m);t++,cnt=0)
    {
        bool relate[50010];
        memset(relate,false,sizeof(relate));
        for(int i=1;i<=n;relation[i]=i,i++);
        for(int c=0,i,j;c<m&&scanf("%d %d",&i,&j);c++,relation[_find(i)]=_find(j));
        for(int i=1;i<=n;i++)
            if(!relate[_find(i)]){cnt++;relate[_find(i)]=true;}
        printf("Case %d: %d\n",t,cnt);
    }
    return 0;
}
