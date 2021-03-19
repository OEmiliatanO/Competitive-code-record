#include <cstdio>
#include <algorithm>
#define getchar_unlocked getchar
#define putchar_unlocked putchar

using namespace std;

typedef short int16;
typedef unsigned short uint16;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef pair<int, int> pii;

int64 n, sum, ans;
char ch, s[15];
int16 index;

int main()
{
    while(true)
    {
        index = n = sum = 0;
        ans = 1;
        while((ch = getchar_unlocked()) && ch != '\n' && ch != EOF)
            n = n * 10 + ch - '0';
        if(ch == EOF)
            break;

        if(n == 0)
        {
            putchar_unlocked('0');
            putchar_unlocked('\n');
            continue;
        }

        while(n)
            sum += !(n & 1), n >>= 1;
        while(sum--)
            ans <<= 1;

        while(ans)
            s[index++] = ans % 10, ans /= 10;
        while(index)
            putchar_unlocked(s[--index] + '0');
        putchar_unlocked('\n');
    }
    return 0;
}
