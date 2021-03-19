#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef short int16;
typedef unsigned short uint16;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef pair<int, int> pii;

int n, a, c, s[2][1001]{}, carries[2][1001]{}, tmp[2];

int main()
{
    s[0][0] = 5, s[1][0] = 6;
    carries[0][0] = 2, carries[1][0] = 3;

    for(int i = 1; i < 1000; ++i)
    {
        tmp[0] = carries[0][i - 1];
        tmp[1] = carries[1][i - 1];

        for(int j = i - 1; j >= 1; --j)
        {
            tmp[0] += s[0][j] * s[0][i - j];
            tmp[1] += s[1][j] * s[1][i - j];
        }

        s[0][i] = tmp[0] % 10;
        s[1][i] = -tmp[1] + (tmp[1] / 10 * 10);
        s[1][i] = (s[1][i] % 10 + 10) % 10;

        carries[0][i] = (s[0][i] * 10 + tmp[0]) / 10;
        carries[1][i] = (s[1][i] * 12 + tmp[1]) / 10;
    }

    while(~scanf("%d", &n))
    {
        --n;
        if(s[0][n] < s[1][n])
        {
            for(int i = n; i >= 0; --i)
                putchar(s[0][i] + '0');
            putchar('\n');
            for(int i = n; i >= 0; --i)
                putchar(s[1][i] + '0');
        }
        else
        {
            for(int i = n; i >= 0; --i)
                putchar(s[1][i] + '0');
            putchar('\n');
            for(int i = n; i >= 0; --i)
                putchar(s[0][i] + '0');
        }
        putchar('\n');
    }

    return 0;
}
