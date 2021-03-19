#include <cstdio>
#include <string.h>
using namespace std;
char s[1010];
int main()
{
    for(int k;scanf("%d %s",&k,&s)!=EOF&&k;)
    {
        int len=strlen(s),cnt=0;
        for(int pointL=1,pointR=k;pointR<len;pointR++,pointL++)
        {
            int L_offset=1,R_offset=1;
            while(L_offset<=pointL&&R_offset+pointR<len)
            {
                bool Find=true;
                for(int L=pointL-L_offset,R=pointR+1;L<pointL&&L>=0&&R>=0&&R<=pointR+R_offset;L++,R++)
                    if(s[L]!=s[R])
                    {
                        Find=false;
                        break;
                    }
                if(Find)
                    cnt++;
                L_offset++,R_offset++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
