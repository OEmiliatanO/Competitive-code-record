#include <cstdio>
#include <string.h>
using namespace std;
int hole[10]{1,0,0,0,0,0,1,0,2,1};
char s[150];
int main()
{
    for(int len,ans=0;scanf("%s",s)!=EOF;ans=0)
    {
        len=strlen(s);
        for(int i=0;i<len;i++)
            ans+=hole[s[i]-'0'];
        printf("%d\n",ans);
    }
    return 0;
}
