#include <stdio.h>
#include <stdlib.h>
char s[20];
int main()
{
    while(gets(s)&&s[0]!=0) printf("hello, %s\n",s);
    return 0;
}
