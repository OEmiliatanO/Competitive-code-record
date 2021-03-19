#include <cstdio>
using namespace std;
char s[17];
int ans;
int main()
{
    while(~scanf("%[^\n]s",s)&&getchar())
    {
        ans=0;
        for(auto ch:s)
        {
            if(!ch) break;
            ans=ans*(-2)+ch-'0';
        }
        printf("%d\n",ans);
    }
    return 0;
}
