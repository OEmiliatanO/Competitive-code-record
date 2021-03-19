#include <cstdio>
#include <cstring>
using namespace std;
char pre[30],infix[30];
int prei=-1,infixlen;
void dfs(int infixl,int infixr)
{
    if(infixl>infixr) return;
    prei++;
    for(int i=0;i<=infixlen;i++)
        if(infix[i]==pre[prei])
        {
            dfs(infixl,i-1);
            dfs(i+1,infixr);
            putchar(infix[i]);
            return;
        }
}
int main()
{
    for(;scanf("%s %s",pre,infix)!=EOF;getchar(),puts(""),prei=-1)
        dfs(0,infixlen=strlen(infix)-1);
    return 0;
}
