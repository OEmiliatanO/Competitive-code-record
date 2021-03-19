#include <cstdio>
#include <cstring>
#define max(x,y) (x)>(y)?(x):(y)
using namespace std;
int Houston[60],MAX_HI=-1;
bool vis[60];
int main()
{
    for(int n;scanf("%d",&n)!=EOF;MAX_HI=-1)
    {
        memset(Houston,0,sizeof(Houston));
        memset(vis,false,sizeof(vis));
        for(int i=0,l,w,h;i<n&&scanf("%d %d %d",&l,&w,&h);MAX_HI=max(MAX_HI,h+1),i++)
            for(int j=l-1;j<=l+w;j++)
                Houston[j]=max(h+1,Houston[j]);
        for(int i=MAX_HI;i>=0;puts(""),i--)
            for(int j=0;j<50;j++)
                if(Houston[j]==i)
                {
                    if(Houston[j-1]<i||Houston[j+1]<i) putchar('+');
                    else putchar('-');
                }
                else if(Houston[j]>i)
                {
                    if(Houston[j-1]<Houston[j]||Houston[j+1]<Houston[j])
                    {
                        if(vis[j]) putchar(' ');
                        else if(Houston[j+1]>=i&&Houston[j-1]>=i) putchar('+'),vis[j]=true;
                        else if(i!=0) putchar('|');
                        else if(vis[j]==false) putchar('+');
                        else putchar(' ');
                    }
                    else putchar(' ');
                }
                else putchar(' ');
        for(int i=1;i<=50;i++)
            printf("%d",i%10);
        puts("");
    }
    return 0;
}
