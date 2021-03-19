#include <cstdio>
using namespace std;
int T,O,ans;
long long cnt;
char ch;
int main()
{
    scanf("%d",&T);getchar();
    while(T--)
    {
        O=ans=cnt=0;
        ch=getchar();
        while(ch!='\n'&&ch!=-1)
        {
            ans=(ch=='O'?(cnt+ans)%1000000007:ans);
            O+=(ch=='O');
            cnt=(ch=='w'?O+cnt:cnt);
            ch=getchar();
        }
        printf("%d",ans);
        putchar('\n');
    }
    return 0;
}
//(1.4s, 136KB)
