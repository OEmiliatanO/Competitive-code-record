#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <stdio.h>

using namespace std;

typedef short int16;
typedef unsigned short uint16;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;

int16 n, d, sIndex;
int tmp;
char ch, s[10];

int main()
{
    while(~scanf("%hd", &n) && getchar_unlocked())
    {
        for(int16 index = n - 1; index >= 1; --index)
        {
            while((ch = getchar_unlocked()) && ch == ' ');
            d = ch - '0';
            ch = getchar_unlocked();
            if(ch != ' ') d = (d << 1) + (d << 3) + ch - '0';
            tmp = d * index;

            if(tmp == 0)
            {
                putchar_unlocked('0');
                putchar_unlocked(' ');
            }
            else
            {
                sIndex = 0;
                s[sIndex++] = ' ';
                while(tmp)
                {
                    s[sIndex++] = tmp % 10 + '0';
                    tmp /= 10;
                }
                --sIndex;
                while(sIndex >= 0)
                    putchar_unlocked(s[sIndex--]);
            }
        }
        while((ch = getchar_unlocked()) && ch != '\n');
        if(n < 2) putchar_unlocked('0');
        putchar_unlocked('\n');
    }
    return 0;
}
