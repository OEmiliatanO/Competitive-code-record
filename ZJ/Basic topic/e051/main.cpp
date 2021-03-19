#include <cstdio>
#include <cstring>
using namespace std;
char s[1001];
int len;
int main()
{
    scanf("%[^\n]s",s);
    len=strlen(s);
    for(int i=1;i<len-1;i++)
        s[i]='_';
    puts(s);
    return 0;
}
