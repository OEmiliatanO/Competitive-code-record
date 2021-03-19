#include <cstdio>
#include <cstring>

using namespace std;

char s[101];
int zero, doublezero, len;


int main()
{
    while(~scanf("%s", s))
    {
        zero = doublezero = 0;
        len = strlen(s);

        for(int i = 0; s[i]; ++i)
        {
            zero += (s[i] == '0');
            doublezero += (s[i] == '0' && s[(i + 1) % len] == '0');
        }

        if(zero * zero < doublezero * len) puts("SHOOT");
        else if(zero * zero > doublezero * len) puts("ROTATE");
        else puts("EQUAL");
    }
    return 0;
}
