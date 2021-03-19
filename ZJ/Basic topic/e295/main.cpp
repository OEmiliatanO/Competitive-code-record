#include <cstdio>
#include <algorithm>
//#define getchar_unlocked() getchar()
//#define putchar_unlocked(x) putchar(x)

using namespace std;

typedef short int16;
typedef unsigned short uint16;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef pair<int, int> pii;

uint a, b, c, y, len;
char ch;

int main()
{
    while(true)
    {
        a = b = 0;
        y = 10, len = 1;

        if(ch == EOF) break;

        while((ch = getchar_unlocked()) && ch >= '0' && ch <= '9')
            a = a * 10 + ch - '0';

        if(ch == EOF) break;

        while((ch = getchar_unlocked()) && ch >= '0' && ch <= '9')
            b = b * 10 + ch - '0';

        c = a + b;

        while(y <= c) y *= 10, ++len;

        while(len--)
        {
            y /= 10;
            putchar_unlocked(c / y + '0');
            c %= y;
        }
        putchar_unlocked('\n');
    }
    return 0;
}
