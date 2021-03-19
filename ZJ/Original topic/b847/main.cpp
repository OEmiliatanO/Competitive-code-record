#include <cstdio>
#include <cstring>
using namespace std;
char s[10000];
int aph[26],totn;
int main()
{
    while(~scanf("%[^\n]s",s)&&getchar())
    {
        totn=0;
        memset(aph,0,sizeof(aph));
        for(auto ch:s)
        {
            if(ch==0) break;
            if((ch>='A'&&ch<='Z'))
                aph[ch-'A']++,totn++;
            else if((ch>='a'&&ch<='z'))
                aph[ch-'a']++,totn++;
        }
        for(auto n:aph)
            printf("%d ",n);
        puts("");
        for(auto n:aph)
            printf("%.2f ",(double)n*100/totn);
        puts("");
    }
    return 0;
}
