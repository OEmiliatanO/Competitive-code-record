#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char s[200];
    int length;
    for(;scanf("%[^\n]s",s)!=EOF&&(length=strlen(s));getchar(),puts(""))
        for(int i=0;i<length;putchar(s[i]-7),i++);
    return 0;
}
