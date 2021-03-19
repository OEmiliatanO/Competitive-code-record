#include <cstdio>
#include <cstring>
using namespace std;
int N,len,on,tw,th;
char one[]="one",two[]="two",three[]="three",s[7];
int main()
{
    scanf("%d",&N);
    while(N--&&scanf("%s",s))
    {
        on=tw=th=0;
        len=strlen(s);
        for(int i=0;i<len;i++)
        {
            on+=(one[i]==s[i]);
            tw+=(two[i]==s[i]);
            th+=(three[i]==s[i]);
        }
        if(len==3&&on>=tw&&on>=th) puts("1");
        else if(len==3&&tw>=on&&tw>=th) puts("2");
        else if(len==5||th>on&&th>tw) puts("3");
    }
    return 0;
}
