#include <cstdio>
#include <cmath>
using namespace std;
int n,m,e,now;
bool _find;
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        _find=false;
        for(int i=n,tmp=0;i<=m;i++,tmp=0)
        {
            now=i;
            e=log10(i)+1;
            while(now!=0&&tmp<=i)
                tmp+=ceil(pow(now%10,e)),now/=10;
            if(i==tmp){_find=true; printf("%d ",i);}
        }
        if(!_find) printf("none");
        puts("");
    }
    return 0;
}
