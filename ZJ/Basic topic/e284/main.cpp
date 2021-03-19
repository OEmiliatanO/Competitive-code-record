#include <cstdio>
#include <algorithm>

using namespace std;

typedef short int16;
typedef unsigned short uint16;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef pair<int, int> pii;

int n;
char ch;

int main()
{
    while(true)
    {
        n = 0;
        while((ch = getchar_unlocked()) && ch != '\n' && ch != EOF)
        {
            n = n * 10 + ch - '0';
        }
        if(ch == EOF)
             break;
        if(n & (n - 1) || !n)
        {
            putchar_unlocked('N');
            putchar_unlocked('o');
        }
        else
        {
            putchar_unlocked('Y');
            putchar_unlocked('e');
            putchar_unlocked('s');
        }
        putchar_unlocked('\n');
    }

    return 0;
}
