#include <cstdio>
#include <cstring>
using namespace std;
char s[50];
int ms,len,num,p;
int scan(int &i)
{
    int r=0;
    while(i<len&&(s[i]<'0'||s[i]>'9')) i++;
    while(i<len&&(s[i]>='0'&&s[i]<='9')) r=r*10+s[i++]-'0';
    return r;
}
int main()
{
    while(~scanf("%[^\n]s",s)&&getchar())
    {
        p=ms=0;
        len=strlen(s);
        while(p<len)
        {
            num=scan(p);
            if(p<len)
                if(s[p]=='h')
                    ms+=num*3600*1000;
                else if(s[p]=='m'&&s[p+1]!='s')
                    ms+=num*60*1000;
                else if(s[p]=='s')
                    ms+=num*1000;
                else if(s[p]=='m'&&s[p+1]=='s')
                    ms+=num;
                else if(s[p]='.')
                {
                    int num2=scan(p);
                    ms+=num*1000+num2*100;
                }
        }
        printf("%d\n",ms);
    }
    return 0;
}
