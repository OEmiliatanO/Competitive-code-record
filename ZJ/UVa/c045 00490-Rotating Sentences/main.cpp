#include <cstdio>
#include <cstring>
using namespace std;
char s[100][100];
int p=0,maxlen=0,len;
inline int max(const int &a,const int &b)
{
    return (a>b?a:b);
}
int main()
{
    memset(s,0,sizeof(s));
    for(;scanf("%[^\n]s",s[p])!=EOF;maxlen=max(maxlen,strlen(s[p++])),getchar());
    for(int i=0;i<maxlen;puts(""),i++)
        for(int j=p-1;j>=0;j--)
            putchar((s[j][i]?s[j][i]:' '));
    return 0;
}
