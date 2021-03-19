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

unsigned int n;
char ch;

int main()
{
    while(true)
    {
        n = 0;
        while((ch = getchar_unlocked()) && ch != '\n' && ch != EOF)
            n = n * 10 + ch - '0';
        if(ch == EOF)
            break;
        while(n--)
        {
            ch = getchar_unlocked();
            if(ch == '0')
            {
                getchar_unlocked();
                ch = getchar_unlocked();
                if(ch == '0')
                {
                    putchar_unlocked('C');
                }
                else
                {
                    getchar_unlocked();
                    ch = getchar_unlocked();
                    if(ch == '0')
                        putchar_unlocked('A');
                    else
                        putchar_unlocked('B');
                }
            }
            else
            {
                getchar_unlocked();
                ch = getchar_unlocked();
                if(ch == '0')
                    putchar_unlocked('E');
                else
                {
                    getchar_unlocked(); getchar_unlocked(); getchar_unlocked();
                    ch = getchar_unlocked();
                    if(ch == '0')
                        putchar_unlocked('F');
                    else
                        putchar_unlocked('D');
                }
            }
            while((ch = getchar_unlocked()) && ch != '\n' && ch != EOF);
            if(ch == EOF)
                break;
        }
        putchar_unlocked('\n');
    }
    return 0;
}
