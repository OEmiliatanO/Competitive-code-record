#include <cstdio>
#include <algorithm>

using namespace std;

typedef short int16;
typedef unsigned short uint16;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef pair<int, int> pii;

char n[900];
int b1, b2, index;
uint64 num;

int main()
{
    while(~scanf("%s %d %d", n, &b1, &b2))
    {
        num = index = 0;
        for(auto ch : n)
        {
            if(!ch) break;
            num = num * b1 + ch - (ch >= '0' && ch <= '9' ? '0' : 'A' - 10);
        }

        while(num)
            n[index++] = (num % b2 > 9 ? num % b2 + 'A' - 10 : num % b2 + '0'), num /= b2;

        while(index--) putchar(n[index]);

        putchar('\n');
    }

    return 0;
}
