#include <cstdio>
#include <string.h>
using namespace std;
char str[100000];
int length;
int main()
{
    for(;scanf("%s",str)!=EOF;)
    {
        length=strlen(str);
        char maxch=str[0],nowch=str[0];
        int maxcnt=1,nowcnt=1;
        for(int i=1;i<=length;i++)
            if(nowch==str[i]) nowcnt++;
            else {maxch=(maxcnt<nowcnt?nowch:maxch); maxcnt=(maxcnt<nowcnt?nowcnt:maxcnt); nowch=str[i]; nowcnt=1; }
        printf("%c %d\n",maxch,maxcnt);
    }
    return 0;
}
