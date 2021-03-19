#include <cstdio>
using namespace std;
int n,tmp;
int main()
{
    while(~scanf("%d",&n))
    {
        printf("TERM %d IS ",n);
        tmp=1;
        while(tmp*(tmp+1)<(n<<1)) tmp++;
        int d=n-((tmp*(tmp-1)>>1)+1);
        if(tmp&1) printf("%d/%d\n",tmp-d,1+d);
        else printf("%d/%d\n",1+d,tmp-d);
    }
    return 0;
}
